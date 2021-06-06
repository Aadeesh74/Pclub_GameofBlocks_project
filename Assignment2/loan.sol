// SPDX-License-Identifier: MIT
pragma solidity >=0.4.25 <0.7.0;

contract MetaCoin {
	mapping (address => uint256) balances;

	event Transfer(address indexed _from, address indexed _to, uint256 _value);

	constructor() public {
		balances[tx.origin] = 100000;
	}

	function sendCoin(address receiver, uint256 amount, address sender) public returns(bool sufficient) {
		if (balances[sender] < amount) return false;
		balances[sender] -= amount;
		balances[receiver] += amount;
		emit Transfer(sender, receiver, amount);
		return true;
	}


	function getBalance(address addr) public view returns(uint256) {
		return balances[addr];
	}
}

contract Loan is MetaCoin {
    mapping (address => uint256) private loans;
     
    event Request(address indexed _from, uint256 P, uint R, uint T, uint256 amt);
    
    address private Owner;

    
    modifier isOwner() {
        require(msg.sender == Owner,"You are not allowed.");
        _;
        
    }
    
    constructor() public {
        Owner = msg.sender;
    }
    
    
    function getCompoundInterest(uint256 principle, uint rate, uint time) public pure returns(uint256) {
         while (time > 0){
             time--;
            principle += principle*rate/100;}
            return principle;
    }
    
    function reqLoan(uint256 principle, uint rate, uint time) public returns(bool correct) {
        uint256 toPay = getCompoundInterest(principle, rate, time);
        // A creditor uses this function to request the Owner to settle his loan, and the amount to settle is calculated using the inputs.
        if (toPay<principle || rate < 1) return false;
        else{
	loans[msg.sender] = toPay;
        emit Request(msg.sender,principle,rate,time,toPay);
        return true;
        }
    }
    
    function getOwnerBalance() public view returns(uint256) {
			return getBalance(Owner); 
		}
    
    function viewDues(address creditor) public view isOwner returns(uint256){
        return loans[creditor];
    }
    
    function settleDues(address creditor) public isOwner returns(bool){
      if (sendCoin(creditor,viewDues(creditor),Owner)) 
      {
          loans[creditor]=0;
          return true;
      }
      else return false;
    }
    
}
