#include <wchar.h>
#include <locale.h>
#include <stdbool.h>

#define MAXLINE 1000

size_t readline(wchar_t out[], size_t limit);
void copy(wchar_t to[], wchar_t from[]);

int main() {
	size_t max;
	wchar_t line[MAXLINE];
	wchar_t longest[MAXLINE];
	size_t len;

	setlocale(LC_ALL, "");

	max = 0;

	while ((len = readline(line, MAXLINE)) > 0) {
		if (len > max) {
			copy(longest, line);
			max = len;
		}
	}

	if (max > 0) { // there was a line
		wprintf(L"%ls", longest);
	}

	return 0;
}

size_t readline(wchar_t out[], size_t limit) {
	size_t i;
	bool done;
	wint_t c;

	i = 0;
	done = false;

	while (!done) {
		if (i + 1 >= limit) {
			done = true;
		} else {
			c = getwchar();
			if (c == EOF) {
				done = true;
			} else {
				out[i] = c;
				i++;

				if (c == '\n') {
					done = true;
				}
			}
		}
	}

	out[i] = L'\0';
	return i;
}

void copy(wchar_t to[], wchar_t from[]) {
	size_t i;

	i = 0;
	while ((to[i] = from[i]) != L'\0') {
		i++;
	}
}
