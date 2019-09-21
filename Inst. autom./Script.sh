#!/bin/bash

echo "S'instalarà el programa de Game of Thrones..."
cd ..
cd 'Codi font'
gcc menu.c funcions.c -o GameOfThrones
echo -e "\n***Executable creat a la carpeta 'Codi font'!***\n"
echo -e "Vols executar-lo ara? si/no"
read resposta

if [ $resposta == "si" ]
then
	./GameOfThrones
else	
	echo -e "Adéu."
fi
