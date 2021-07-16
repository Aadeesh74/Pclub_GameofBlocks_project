# First-past-the-post voting

In a first-past-the-post (FPTP or FPP; sometimes formally called single-member plurality voting or SMP; sometimes called choose-one voting for single-member districts,
voters cast their vote for a candidate of their choice, and the candidate who receives the most votes wins (even if the top candidate gets less than 50%, which typically happens
when there are more than two popular candidates).

## Instructions:

1. The one who deploys (owner of the contract <b>Ballot</b>) is called <b>Chairperson</b>.<br> 
Only chairperson can give rights to voters - <b>rightToVote</b>, and only after that they can vote. <br>
Only chairperson can give rights to contestants - <b>rightToContest</b>, and only after that they can stand in election.<br>
When these functions are used, all voters and contestants registered till then get verified by Chairperson.
2. Voters can <b>register</b> themselves just passing their name and a true/false in <b>ascontestant</b> if they want to stand in election as contestant.<br>
3. Once a voter or contestant registers, they get added to the arrays - voters or contestants. (Note: Every contestant is also a voter so they exist in both the arrays)
4. <b>ShowContestantIndex</b> function gives the index of contestant by passing their name.
5. <b>vote</b> function does the main process - to vote by entering contestant's name and their respective index. <br>
Requirements: Voter and contestant must be verified. Voter hasn't voted yet. proposalIndex must match with contestant's name.
6. <b>WinnerName</b> function compares the total votes to each contestant to give the winner name.<br>
This can only be run by the Chairperson.
