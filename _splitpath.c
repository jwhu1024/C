void _splitpath(const char *path, char *drive, char *dir, char *fname, char *ext)
{
	char *tmp_path;
	int conut;
	char tmp[PATH_MAX];
	char tmp_name[PATH_MAX];
	char tmp_ext[PATH_MAX];
	int check=0;
	int check_1=0;
	int i,j=0,k=0;
	int conut_1,conut_2, conut_3;

	tmp_path = NULL;
	if( ( realpath(path, tmp_path) == NULL) ) {
		tmp_path = path;
	}

	conut=0;
	do {
		if( tmp_path[conut] == ':')	{
			check=1;
			conut_1 = conut;
		}
		if (tmp_path[conut] == '/')	{
			conut_2 = conut;
		}
		if (tmp_path[conut] == '.')	{
			check_1 = 1;
			conut_3 = conut;
		}
		conut++;
	} while(tmp_path[conut] != '\0');


	if ( check == 1) {
		fname = basename(tmp_path);
		dir = dirname(tmp_path);
		for( i = 0 ; i< conut; i++)	{
			if ( dir[i] != ':')	{
				if( i>=2 ) {
					tmp[i-2]=dir[i];
				}
			} else {
				drive=dir[i-1];		
			}
		}
		memset(dir,0,sizeof(dir));
		strcpy(dir,tmp); 
	} else {
		fname = basename(tmp_path);
		dir = dirname(tmp_path);
	}


	if (check_1 == 1) {
		while( fname[j] != '\0') {
		#ifdef 0  //¦Z?¦W¤£?"."
			if ( fname[j] == '.') {
				k=j+1;
			} else {
				tmp_name[j]=fname[j];
				if (j >=k && k != 0) {
					tmp_ext[j-k]=fname[j];
				} 
			}
		#endif 
		#ifdef 1  ////¦Z?¦W?"."
			if ( fname[j] == '.') {
				k=j;
			}

 		    if ( j >= k && k !=0 ) {
				tmp_ext[j-k]=fname[j];
			} else {
				tmp_name[j]= fname[j];
			}
		#endif
		   j++;
		}
		memset(ext,0,sizeof(ext));
		memset(fname, 0, sizeof(fname));
		strcpy(fname, tmp_name);
		strcpy(ext,tmp_ext);
	}
	printf("drive=====%c\n",drive);
	printf("dir=======%s\n",dir);
	printf("fname========%s\n",fname);
	printf("ext======%s\n",ext);
}