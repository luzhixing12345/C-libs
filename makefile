
.PHONY: clean

main: main.cpp
	g++ $^ -o $@

clean:
	-rm -f main