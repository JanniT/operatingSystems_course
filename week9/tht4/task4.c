#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 1024

struct lines
{
	char * string;
	struct lines * prev;
	struct lines * next;
};

int read_lines(struct lines ** line, FILE * stream)
{
	char tmp[MAXLEN];
    struct lines *lp, *prev_lp = NULL;
	
	while (fgets(tmp, MAXLEN, stream) != NULL) {
		
		if (*line == NULL) {
			if ((*line = lp = malloc(sizeof(struct lines))) == NULL) {
				fprintf(stderr, "ERROR: could not allocate memory\n");
				return -1;
			}
			lp->prev = lp->next = NULL;
		} else {
			if ( (lp->next = malloc(sizeof(struct lines))) == NULL) {
				fprintf(stderr, "ERROR: could not allocate memory\n");
				return -1;
			}

			/* Here you should insert the lines that link the list correctly */
            // linking the previous node
            lp->next->prev = lp; 
            lp = lp->next;
            lp->next = NULL;
		}
		
		if ( (lp->string = malloc(strlen(tmp) + 1)) == NULL) {
			fprintf(stderr, "ERROR: could not allocate memory\n");
			return -1;
		}
		
		strcpy(lp->string, tmp);
        // Store previous node
        prev_lp = lp; 
	}

    // Set the head of the list to the first node
    while (prev_lp != NULL && prev_lp->prev != NULL)
        prev_lp = prev_lp->prev;
    *line = prev_lp;
	
	return 0;
}

void print_lines(struct lines * line, FILE * stream)
{
	struct lines * lp;
	
	/* Here you should implement a loop that prints the lines in reverse order. 	*/
	/* First you need to follow the links from the first node to the last node.	*/ 	

    lp = line;
    while (lp != NULL)
    {
        fprintf(stream, "%s", lp->string);
        lp = lp->next;
    }

}

void delete_lines(struct lines * line)
{
	struct lines * lp;
	
	lp = line;
	while (lp != NULL) {
		line = lp->next;
		free(lp->string);
		free(lp);
		lp = line;
	}
}

int main(void)
{
	struct lines * line = NULL;
	
	if (read_lines(&line, stdin) == -1)
		exit(1);
	print_lines(line, stdout);
	delete_lines(line);
	
	return 0;
}