# One-Time-Pad
This is a script to Encrypt and Decrypt a message with a one-time pad. It was made for my Discrete Mathematics class Cryptography section.

## Instructions
 - Simply edit the "message" char array and run the program. It will output the binary one-time pad, the message in binary, the encrypted message, the decrypted message, and the message back in ASCII text.

## Code Blocks
 - First, the program generates a binary string pad
 - Next, the message is converted into a long binary string
 - The binary message is encrypted by XOR with the binary pad
 - Decryption is done by again XOR the pad but with the encrypted binary
 - Finally, the decrypted binary is converted into the original ASCII text
