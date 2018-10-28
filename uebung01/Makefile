all: gsl_ran first_diff break_words line_mean
	
gsl_ran: gsl_ran.o
	gcc -L/usr/local/lib gsl_ran.o -lgsl -lgslcblas -o gsl_ran

gsl_ran.o: gsl_ran.c
	gcc -c gsl_ran.c

first_diff: first_diff.c
	gcc -o first_diff first_diff.c

break_words: break_words.c
	gcc -o break_words break_words.c

line_mean: line_mean.c
	gcc -o line_mean line_mean.c

clean:
	rm *o
	rm gsl_ran
	rm break_words
	rm first_diff
	rm line_mean