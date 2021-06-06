In this smart contract we took an metacoin template and created a loan contract in that we added some functions like getCompoundInterest,reqLoan,getOwnerBalance,viewDues,settleDues

**getCompoundInterest**  is a pure state function (since it doesn't change or view any state variables) and its public
and anyone can calculate compound interest using it by passing princlple amount ,rate of interest , and time as the parameters .

**reqLoan** is a public function i.e anyone can request to settle his amount by entering principle_amount,rate and time as the required parameters
and respectively their balances gets updated that they can check using getBalance function.

**settleDues** is only accessible to owner and only he can settle dues of the creditor by entering creditors address.

**viewDues** is only accessible to owner and only he can view the Dues he have to pay to the respective creditor by entering his address.

**getOwnerBalance** is a public function and is in view state as it don't modifies any state variable it just views them 
and anyone can view the owner's balance using this function.

# Instructions to test this
1.Open the Remix IDE and create a new *.sol file.

2.Copy from this loan.sol and paste in the new file in Remix.

3.From the left side menu compile the file.

4.Now go to the deploy and run transactions and select account of your choice and remember that,
as you deploy the contract with this account so this account becomes the owner.

5.for an example lets say the owner to settle our amount of 1000 @ rate of 10% per annum for 10 years, for this follow this:-

  i) select an another account that want to settle his amount.
  
  ii) click on to reqLoan and enter the principle_amount,rate,time.Now in the loan mapping your amount gets updated.
  
  iii) to verify change to your owner account and go to viewDues and enter creditors address(you can copy when u change or select the account)
  you will get amount that is to be settled and in our case its 2591.
  
  iv) now go to settleDues and enter the creditors address whose amount u want to settle and you are done.
  
  v) to verify go again to viewDues and u see the amount goes to 0.And even you can go to getBalance 
  and check by entering your address that your balance gets updated by 2591.
  
  vi) you can also check owner's balance from any account and that also gets updated.

