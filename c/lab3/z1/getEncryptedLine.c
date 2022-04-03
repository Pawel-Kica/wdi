char *getEncryptedLine()
{
    char *buffer = NULL;
    int len;
    int r = getline(&buffer, &len, stdin);

    if (r != -1)
    {
        encryptCaeser(buffer, r - 1);
        return buffer;
    }
    else
    {
        free(buffer);
        return NULL;
    }
}