# EZrev | NoobHacker

- Description: Rev is EZ!

EZrev.class:bin/EZrev.class

# Write up

Notice the `.class` extension which implies this is a java compiled class. Opening this up in a decompiler, we see that it expects an argument, does some mathematical operations and shuffling on it and then compares it to a stored array. We can reverse this process by starting with the stored array, doing the mathematical operations and shuffling in reverse, which gives the flag. (Refer solve script for exact details)

# Flag - n00bz{r3v_1s_s0_e4zy_r1ght??!!}
