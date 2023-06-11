```markdown
# Club_N00b | 0xBlue

- Description: Can you get in the club?

- Hint1: Try the home page.

source_for_chall:public/

# Write up

The homepage displays some filler text, the word "radical" with some css styling, and a button. Clicking the button takes you to `/check?secret_phrase=nope`. Changing the phrase to `radical`(case-sensitive, has to be lowercase) takes you to `/members_only.html?flag=n00bz{see_you_in_the_club_acting_real_nice}`. The flag is comes from the environment variable FLAG on the server, so you have to start the chall with:
	`FLAG=n00bz{see_you_in_the_club_acting_real_nice} cargo run --release`
^ you run that command in the same directory as `Cargo.toml`, so you can copy the public/ dir to a vm, cd into it and run that command to test

I can change the enironemt variable name later if it clashes with something else

# Flag - n00bz{see_you_in_the_club_acting_real_nice}
```

