all: solution


solution: solution.cpp
	g++ -std=c++17 $< -g -o $@

backup:
	@read -p "Enter backup name: " name;\
	cp solution.cpp "$name"_solution.cpp;\
	cp template.cpp solution.cpp;

reset:
	cp template.cpp solution.cpp;

load:
	@read -p "Enter backup name: " name;\
	cp "$name"_solution.cpp solution.cpp;

clean:
	rm -f *.o

.PHONY: all clean run backup
