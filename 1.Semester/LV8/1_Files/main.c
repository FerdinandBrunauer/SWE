#define _CRT_SECURE_NO_WARNINGS // Disable warning when using "unsafe" functions
#include <stdlib.h>
#include <stdio.h>

#define MIN_WORD_LENGTH 3

int linecount(char *location)
{
	FILE *fp;
	fp = fopen(location, "r");

	int lines = 1 /* First line is already included */, ch;
	while (!feof(fp))
	{
		ch = fgetc(fp);
		if (ch == '\n')
		{
			lines++;
		}
	}

	fclose(fp);
	return lines;
}

int wordCount(char *location)
{
	FILE *fp;
	fp = fopen(location, "r");

	int words = 0, wordLength = 0, ch;
	while (!feof(fp))
	{
		ch = fgetc(fp);
		if (ch == ' ')
		{
			words += wordLength >= MIN_WORD_LENGTH ? 1 : 0;
			wordLength = 0;
		}
		else
		{
			wordLength++;
		}
	}

	fclose(fp);
	return words;
}

int charCount(char *location)
{
	FILE *fp;
	fp = fopen(location, "r");

	int chars = 0, ch;
	while (!feof(fp))
	{
		ch = fgetc(fp);
		if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'))
		{
			chars++;
		}
	}

	fclose(fp);
	return chars;
}

int copyFileChars(char *src, char *dst)
{
	int writtenChars = 0;
	FILE* srcFile = fopen(src, "r");
	FILE* dstFile = fopen(dst, "w+");
	int ch;
	while (!feof(srcFile))
	{
		ch = fgetc(srcFile);
		fputc(ch, dstFile);
		writtenChars++;
	}

	fclose(srcFile);
	fflush(dstFile);
	fclose(dstFile);

	return writtenChars;
}

int copyFileBinary(char *src, char *dst)
{
	int writtenChars = 0;
	char buffer[59];
	size_t bytes;
	FILE* srcFile = fopen(src, "r");
	FILE* dstFile = fopen(dst, "w+");
	while (0 < (bytes = fread(buffer, 1, sizeof(buffer), srcFile)))
	{
		fwrite(buffer, 1, bytes, dstFile);
		writtenChars += bytes;
	}

	fclose(srcFile);
	fflush(dstFile);
	fclose(dstFile);

	return writtenChars;
}

int main()
{
	char file[] = "Text.txt";
	char file1[] = "Text1.txt";

	printf("Linecount from %s is %d\n", file, linecount(file));
	printf("Words in %s: %d\n", file, wordCount(file));
	printf("There are %d characters in the file %s\n", charCount(file), file);
	printf("Copy from %s to %s. %d characters copied\n", file, file1, copyFileChars(file, file1));
	printf("Copy from %s to %s. %d bytes copied\n", file, file1, copyFileBinary(file, file1));
	// TODO Diff


	getch();
	return 0;
}