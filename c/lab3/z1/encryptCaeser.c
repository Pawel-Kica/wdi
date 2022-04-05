void encryptCaeser(char *msg)
{
    int i;
    int length = strlen(msg);
    int shift = length;

    for (i = 0; i < length; i++)
    {
        if (msg[i] != ' ')
        {
            for (int j = i; j < length; j++)
            {
                if (msg[j] == ' ')
                {
                    shift = j - i;
                    break;
                }
            }
            break;
        }
    }

    for (i = 0; i < length; i++)
    {
        if (msg[i] != ' ')
        {
            if (msg[i] >= 65 && msg[i] <= 90)
                msg[i] = ((msg[i] - 65 + shift) % 26) + 65;
            else if (msg[i] >= 97 && msg[i] <= 122)
                msg[i] = ((msg[i] - 97 + shift) % 26) + 97;
        }
    }
}
