all : tuxquest clean

exam : Exam.tex Exam.pdf clean

tuxquest : src/tuxquest.c src/inventory.c src/inventory.h src/stats.c src/stats.h src/utils.c src/locations.c src/locations.h docs documentation
	gcc -Wall -o tuxquest src/tuxquest.c

Exam.pdf : 
	pdflatex Exam.tex

test : tuxquest
	echo "Testing tuxquest"
	bash ./scripts/script.sh

Doxyfile :
	doxygen -g

docs : Doxyfile
	doxygen Doxyfile

documentation : 
	mkdir documentation
	mkdir documentation/docs

profile : src/tuxquest.c src/inventory.c src/inventory.h src/stats.c src/stats.h src/utils.c src/locations.c src/locations.h docs documentation
	gcc -Wall -pg -o tuxquest src/tuxquest.c
	find ./testing -type f -name "fullAdventure" | xargs cat | ./tuxquest
	gprof tuxquest 

coverage : src/tuxquest.c src/inventory.c src/inventory.h src/stats.c src/stats.h src/utils.c src/locations.c src/locations.h docs documentation
	gcc -fprofile-arcs -ftest-coverage -o tuxquest src/tuxquest.c
	find ./testing -type f -name "fullAdventure" | xargs cat | ./tuxquest
	gcov tuxquest.c

clean : 
	rm -rf src/*.o *~ */*~ *.aux *.log *.out
