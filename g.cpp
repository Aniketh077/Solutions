/*

g)
Explain a piece of code that you wrote which you are proud of? if you have not written any

code, please write your favorite subject in engineering studies. We can go deep into that

subject

*/

/*
g)   This is a piece of code that I have written in one of my projects under professor.

*/

def add(request):
    global r
    df = pd.read_excel('C:\\Users\\anike\\projects\\webapp\\BTP_EXCEL.xlsx')
    lang_input = request.POST.get("num1", "").strip()

    # check if input is empty
    if not lang_input:
        return render(request, "home.html", {"result": "", "num1": ""})

    result = []
    for char in lang_input:
        temp_braillie = ''
        if(char == " "):
            temp_braillie = " "
            result.append(temp_braillie)
        else:
            for x in df.index:
                if (df.loc[x, "ODIA"] == char) or (df.loc[x, "TELUGU"]) == char or (df.loc[x, "ENGLISH_SMALL"] == char) or (df.loc[x, "Bengali"] == char) or (df.loc[x, "Hindi"] == char) or (df.loc[x, "ENGLISH_CAPITAL"] == char) or (df.loc[x,"English_grade2"]==char) or (str(df.loc[x, "ENGLISH_CAPITAL"]) == str(char)):
                    temp_braillie += str(df.loc[x, "Braille ascii_1"]).replace('nan', '  ')
                    temp_braillie = temp_braillie.strip()
                    if (len(temp_braillie) > 6):
                        temp = ""
                        count = 0
                        for i in range(len(temp_braillie)):
                            count += 1
                            if (i == len(temp_braillie) - 1):
                                temp += temp_braillie[i]
                                result.append(temp)
                                break
                            elif (count <= 6):
                                temp += temp_braillie[i]
                            else:
                                result.append(temp)
                                count = 1
                                temp = temp_braillie[i]
                    else:
                        result.append(temp_braillie)

    if not any(char != ' ' for char in result):
        return render(request, "home.html", {"result": "Please enter a valid text!", "num1": lang_input})
    else:
        r = ""
        try:
            # Add 2 character spaces to the first line
            r += "  " + result[0].encode('latin_1').decode('unicode_escape')

            for i in range(1, len(result)):
                if result[i] == "\\u2808":
                    r = r[:-1] + result[i].encode('latin_1').decode('unicode_escape') + r[-1]
                elif result[i] == " ":
                    r += " ‎" * 3
                else:
                    r += result[i].encode('latin_1').decode('unicode_escape')

                if (i+1) % 37 == 0:
                    r += '\n  '

                if (i+1) % (37*25) == 0:
                    r = "  " + r  # add 2 character spaces to the beginning of each line after the first one
                    break

            r = "\n" + r  # add a new line before the result to start from the second line



            return render(request, "home.html", {"result": r, "num1": lang_input})

        except Exception as e:
            return render(request, "home.html", {"result": "Please enter a valid text!", "num1": lang_input})


explanation: 
This code defines a function named add that takes a request object as an argument.
The pd module is imported to read an Excel file, and the path to the file is hardcoded as 'C:\\Users\\anike\\projects\\webapp\\BTP_EXCEL.xlsx'. The function reads a user input from a form field named "num1" and strips any leading or trailing white space. If the input is empty, it renders the "home.html" template with empty values for result and num1.Otherwise, the function converts each character in the input into Braille using a Braille ASCII code from the Excel file, and concatenates them into a string. If a character is not found in the Excel file, it is skipped. The Braille ASCII code is split into blocks of 6 characters, with each block representing a Braille character. If a block contains more than 6 characters, it is split into smaller blocks of 6 characters each. If all characters in the resulting Braille string are spaces, it renders the "home.html" template with an error message. Otherwise, it prepares the Braille string for display by adding two spaces to the beginning of the first line, inserting spaces after every 37 characters, and breaking the string into multiple lines with 25 lines per page. The prepared string is then rendered in the "home.html" template with the input value.
