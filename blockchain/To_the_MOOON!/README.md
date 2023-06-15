# To_the_MOOON! | 0xBlue

- Description: Because cryptocurrency is entirely unhackable, everyone's tokens are going to the MOOOON! Everyone's but mine, that is. How about this: if you can get my TTMCOIN's price high enough, I'll give you the flag. That sound fair?

- **Required Note 1:** This chall has to be solved in remix - https://remix.ethereum.org/, using the first address shown(`0x5b3...eddc4`)
- **Required Note 2:** The final flag is the transaction hash from calling the `solve()` function(as a string) XORed with `575105531e4f120e1c6d115d5d126d5d4e3a43590f59074439425a525616515f5b4e4c5b000057434d475b416f4e5b57473c0848694158095b56173b170a5d51`(as hex)
- **Required Note 3:** The flag "repeats" in the output you get, but it should be clear what to submit. If not, please open a ticket.
-  Note 4: If the output isn't wrapped in `n00bz{...}`. you may need to reload the page, and solve the chall in as few steps as possible. If it still isn't working but you have a solution, we'll give you the flag.

> Ex: If you get `0x7bff` as the hash, you should xor "7bff"(as a string) with `575105531e4f120e1c6d115d5d126d5d4e3a43590f59074439425a525616515f5b4e4c5b000057434d475b416f4e5b57473c0848694158095b56173b170a5d51`(as hex).
> The output will already be wrapped in `n00bz{...}`

TTMCoin.sol:attachments/TTMCoin.sol

# Write up

use https://remix.ethereum.org
note: expected transaction hash is `0x9a51d4efe2f23f207e48c5b0f7463d7349150059603809493ce1669e73cdbd94`


__steps:__

__setup:__

1. copy and paste contract code into any contract or make a new one
2. remix should auto-compile the contract for you
3. click on the 4th icon(it will show "DEPLOY & RUN TRANSACTIONS" when you click)
4. hit "Deploy"(orange button)


__steps to actually solve:__

call `buy(someNumber)` and send 110 Wei

5. put any number >= 0 and <= 10 in the field for "buy"(red button)
6. put 110 in the "Value" box above(should show "Wei" next to it)
7. click the "buy" button

__call `setPrice()`__

8. press the orange "setPrice()" button

__call `solve()`__

9. press the orange "solve()" button

10. click on the transaction(see image below)
    ignore the other values, just make sure its the right transaction

    should say `TTMCoin.solve()`
11. get the hash of the transaction
    
    after clicking on it, scroll down a bit till you see `transaction hash`

12. that's it! the rest of the chall is on cyberchef, so i dont need that checked

13. if you want to get the flag anyway, XOR the hash with:
    `575105531e4f120e1c6d115d5d126d5d4e3a43590f59074439425a525616515f5b4e4c5b000057434d475b416f4e5b57473c0848694158095b56173b170a5d51`
# Flag - n00bz{why_wont_my_wallet_underflow}

