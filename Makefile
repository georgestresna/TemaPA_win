build:
	gcc main.c Task1.c liste.c -o lanParty
run:
	./lanParty c.in d.in r.out
clean:
	rm -f lanParty


