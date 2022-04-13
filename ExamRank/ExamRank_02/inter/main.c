#include <unistd.h>

int main(int argc, char **argv)
{
	int i = 0;
	int j = 0;
	int k = 0;
	int flag = 0;
//	//char argv[][]= "ddf6vewg64f" "gtwthgdwthdwfteewhrtag6h4ffdhsd";
//	//char argv[2][] = "gtwthgdwthdwfteewhrtag6h4ffdhsd";
//	char *argv1 = "ddf6vewg64f";
//	char *argv2 = "gtwthgdwthdwfteewhrtag6h4ffdhsd";
	if (argc == 3)
	{
		while (argv[1][i])
		{
			k = 0;
			while (k < i)
			{
				flag = 0;
				if (argv[1][i] == argv[1][k])
				{
					flag = 1;
					break;
				}
				k++;
			}
			if (flag == 1)
				i++;
			else
			{
				j = 0;
				while (argv[2][j])
				{
					if (argv[2][j] == argv[1][i])
					{
						write(1, &argv[2][j], 1);
						break;
					}
					j++;
				}
				i++;
			}
		}
	}
	write(1, "\n", 1);
	return (0);
}

