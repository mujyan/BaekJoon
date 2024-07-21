words = {"CU":"see you",
":-)":"I’m happy",
":-(":"I’m unhappy",
";-)":"wink",
":-P":"stick out my tongue",
"(~.~)":"sleepy",
"TA":"totally awesome",
"CCC":"Canadian Computing Competition",
"CUZ":"because",
"TY":"thank-you",
"YW":"you’re welcome",
"TTYL":"talk to you later"
}
while True:
    w = input()
    if w in words:
        print(words[w])
    else:
        print(w)
    if w == "TTYL":
        break