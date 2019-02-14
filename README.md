# SecureProgramming
Secure programming practices that should be implemented.

Writing a program that takes a user input for username and password.
Checks with the configuration file (Which stores the passwords(Passwords are encrypted)).
If the password are correct provides access to the Secret File(Which on the system, cannot be opened directly)
Note the program runs with SUID Permissions.
NOTE: The username is take from the system(user is not allowed to input it), and only the user from a system with a particular name can access it.

Note:
File permission:
Attacker has

Config file(.cfg) - only read permissions
Secret file(.txt) - no access (read write or execute)
Log file(.log) - only read access.
Program file(.cc) - only read access.
Executable(.exe) - cannot be edited.


The Attacker must discover the contents of the Secret File.
