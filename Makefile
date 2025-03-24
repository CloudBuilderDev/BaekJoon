all: solution


solution: solution.cpp
	g++ -std=c++17 $< -g -o $@

backup:
	@read -p "Enter backup name: " name;\
	cp solution.cpp "$name"_solution.cpp;\
	cp template.cpp solution.cpp;

clean:
	rm -f solution *.o

.PHONY: all clean run backup
