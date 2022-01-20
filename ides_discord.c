//xtra est ma vairable static
while (((ret = read(fd, buf, BUFFER_SIZE)) > 0))
{
...
}
if ((*xtra) != NULL) //si j'ai encore des choses a lire dans ma var static
    {
        buf[ret] = '\0';
        *xtra = ft_strjoin(*xtra, buf); //"j'actualise" ma variable static en faisant un join avec ce qu'il ya dans le buf
        while ((*xtra)[i] && (*xtra)[i] != '\n' && (*xtra)[i] != '\0')
            i++;
        if ((*xtra)[i] == '\n')
        {
            *line = ft_substr(*xtra, 0, i); //je mets le contenu de ma ligne dans ma vairanle *line
            i = i + 1; //ca cest pour ne pas compter le \n
            len = ft_strlen(*xtra + i) + 1;
            ft_memmove(xtra, xtra + i, len);
            return (1);
        }
        else if ((*xtra)[i] == '\0') 
        {
            *line = ft_substr(*xtra, 0, i); //je copie le contenu de ma derniere ligne dans ligne
            len = ft_strlen(*xtra + i) + 1;
            ft_memmove(xtra, xtra + i, len);
            return (0);
        }
    }
    else if (*(xtra) == NULL)
    {
        if (!(*line = malloc(sizeof(char *) * 0))) //si je n'ai plus rien a lire je renvoie \0. Meme si j'enleve cette partie jai un leak
            return (-1);
        (*line)[0] = '\0';
    }
    return (0);

(mon join au cas ou) : 
char    *ft_strjoin(char *s1, char *s2)
{
int        len1;
    int        len2;
    int        i;
    char    *res;

    if (s1 == NULL)
        return (ft_strdup(s2));
    if (s2 == NULL)
        return (NULL);
    len1 = ft_strlen(s1);
    len2 = ft_strlen(s2);
    if (!(res = (char *)malloc(sizeof(char) * \
                    ((ft_strlen(s1) + ft_strlen(s2)) + 1))))
        return (NULL);
    i = -1;
    while (++i < len1)
        res[i] = s1[i];
    free(s1);
    s1 = NULL;
    i = -1;
    while (++i < len2)
        res[i + len1] = s2[i];
    res[i + len1] = '\0';
    return (res);
}
