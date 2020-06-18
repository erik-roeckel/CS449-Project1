// Erik Roeckel (efr11)

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>


typedef struct Tag {
	char songTag[3];
	char songTitle[30];
	char artist[30];
	char album[30];
	char year[4];
	char comment[28];
	char zero;
	unsigned char track;
	unsigned char genre;

} Tag;

int is_field_specified(char* field, int argc, char** parameters){
	int exists = 0;
	int i;
	for(i = 1; i < argc -1; i++){
		if(strcmp(field, parameters[i]) == 0){
			exists = i;
			break;
		}
	}

	return exists;
}



int main(int argc, char **argv)
{
	Tag tag;
	FILE* mp3 = fopen(argv[1], "rb");
	FILE* output = fopen(argv[1], "wb");
	if(argc == 1){
		printf("%s\n", "How it works: this program will first check if your mp3 file exists. If your file exists, it will then check to see if your file already has a prexisting ID3 tag. If it has a pre-existing ID3 tag it will be modified and added to the end of your file, and the same with a file that doesn't have an ID3 tag. Then the contents of your ID3 tag will be displayed on the screen. You can also modify your ID3 tag using the command line");
		exit(1);

	}
	if(strcmp(tag.songTag, "TAG") != 0)
		{
			printf("%s\n", "Your file has no ID3 tag, adding one for you.");
			fwrite(tag.songTag, 3, -sizeof(tag), mp3);
		}
	if(mp3 == NULL)
		{
			printf("%s\n", "File doesn't exist, exiting...");
			exit(1);
		}
	fseek(mp3, -128, SEEK_END);
	fread(&tag, sizeof(tag), 1, mp3);

	if(is_field_specified("-title", argc, argv))
	{
		int title_index = is_field_specified("-title", argc, argv) + 1;
		char* title_value = argv[title_index];
		strcpy(tag.songTitle, title_value);
	}
	else{
		memset(&tag.songTitle, 0 , (int)sizeof(tag.songTitle));
	}

	if(is_field_specified("-artist", argc, argv))
	{
		int artist_index = is_field_specified("-artist", argc, argv)+ 1;
		char* artist_value = argv[artist_index];
		strcpy(tag.artist, artist_value);
		fwrite(tag.artist, 30, sizeof(tag.artist), mp3);
	}
	else{
		memset(&tag.artist, 0 , (int)sizeof(tag.artist));
	}
	if(is_field_specified("-album", argc, argv))
	{
		int album_index = is_field_specified("-album", argc, argv) + 1;
		char* album_value = argv[album_index];
		strcpy(tag.album, album_value);
	}
	else{
		memset(&tag.album, 0 , (int)sizeof(tag.album));
	}
	if(is_field_specified("-year", argc, argv))
	{
		int year_index = is_field_specified("-year", argc, argv)+ 1;
		char* year_value = argv[year_index];
		strcpy(tag.year, year_value);
	}
	else{
		memset(&tag.year, 0 , (int)sizeof(tag.year));
	}
	if(is_field_specified("-comment", argc, argv))
	{
		int comment_index = is_field_specified("-comment", argc, argv) + 1;
		char* comment_value = argv[comment_index];
		strcpy(tag.comment, comment_value);
	}
	else{
		memset(&tag.comment, 0 , (int)sizeof(tag.comment));
	}
	if(is_field_specified("-track", argc, argv))
	{
		int track_index = is_field_specified("-track", argc, argv) + 1;
		char track_value = atoi(argv[track_index]);
		tag.track = track_value;
	}
	else{
		memset(&tag.track, 0 , (int)sizeof(tag.track));
	}
	
	printf("Title: '%.*s'\n", (int)sizeof(tag.songTitle), tag.songTitle);
	printf("Artist: '%.*s'\n", (int)sizeof(tag.artist), tag.artist);
	printf("Album: '%.*s'\n", (int)sizeof(tag.album), tag.album);
	printf("Year: '%.*s'\n", (int)sizeof(tag.year), tag.year);
	printf("Comment: '%.*s'\n", (int)sizeof(tag.comment), tag.comment);
	printf("Track: '%d'\n", (int)tag.track);
	printf("Genre: '%d'\n", (int)tag.genre);

	fclose(mp3);
	fclose(output);
	return 0;


}