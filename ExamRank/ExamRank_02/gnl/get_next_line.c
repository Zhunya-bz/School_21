int  get_next_line (char **line)
{
	int i;
	char buff;

	i = 0;
	if (line == NULL)
		return (-1);
	*line = malloc(sizeof(char) * 100);
	while (read(0, &buff, 1) > 0)
	{
		if (buff == '\n')
		{
			(*line)[i] = '\0';
			return (1);
		}
		(*line)[i] = buff;
		i++;
	}
	(*line)[i] = '\0';
	return (0);
}
