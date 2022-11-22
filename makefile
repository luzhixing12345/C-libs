
.PHONY: clean

main: test.c
	gcc $^ -o $@
	./$@

clean:
	-rm -f main