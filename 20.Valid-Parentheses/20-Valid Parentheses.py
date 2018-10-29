def isValid(s):
    """
    :type s: str
    :rtype: bool
    """
    if len(s) == 0 or len(s)%2 !=0 :
        return False
    if s[0] in [')', ']', '}']:
        return False
    temp = []
    for i in range(len(s)):
        # print(s[i])

        if s[i] in ['(', '[', '{']:
            temp.append(s[i])
        elif (temp[len(temp)-1] == '(' and s[i] == ')' \
                or temp[len(temp)-1] == '[' and s[i] == ']' or temp[len(temp)-1] == '{' and s[i] == '}'):
            a = temp.pop()
            print(a)
            print(s[i])
        else:
            return False
    if len(temp) != 0:
        return False
    else:
        return True

if __name__ == '__main__':
    s = "(()])}[}[}[]][}}[}{})][[(]({])])}}(])){)((){"
    print(isValid(s))