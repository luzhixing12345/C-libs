
.PHONY: clean

display: display.cpp output.hpp
	@g++ display.cpp -o display
	@./display

clean:
	-rm -f display.exe output.txt
	cls