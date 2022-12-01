make re
make clean

echo ""
echo "############################################"

echo "MAUVAIS NOMBRE D'ARGUMENT: [./replacer \"test1\" \"123\" \"abcdef\" \"judas\"]"
./replacer "test1" "123" "abcdef" "judas"
echo "############################################"


echo "TEST UN FICHIER INEXISTANT: ./replacer \"mdrrr\" \"123\" \"abcd\""
echo "cat mdrrr:"
cat mdrrr
echo ""

./replacer "mdrrr" "123" "abcd"

echo "cat mdrrr.replace:"
cat mdrrr.replace
echo "############################################"


echo "TEST UN FICHIER SANS PERMISSION DE LECTURE: ./replacer \"noread\" \"you\" \"abc\""
echo "cat noread:"
cat noread
echo ""

./replacer "noread" "you" "abc"

echo "cat noread.replace:"
cat noread.replace
echo "############################################"


echo "TEST REMPLACER DU NULL PAR QQCHOSE: [./replacer \"test1\" \"\" \"judas\"]"
./replacer "test1" "" "judas"
echo "############################################"


echo "TEST SIMPLE: ./replacer \"simple\" \"123\" \"abcd\""
echo "cat simple:"
cat simple
echo ""

./replacer "simple" "123" "abcd"

echo "cat simple.replace:"
cat simple.replace
echo "############################################"


echo "TEST AVEC DOUBLE OCCURRENCE SUR UNE LIGNE: [./replacer \"double\" \"123\" \"abcd\"]"
echo "cat double:"
cat double
echo ""

./replacer "double" "123" "abcd"

echo "cat double.replace:"
cat double.replace
echo "###########################################"


echo "TEST REMPLACER PAR NULL: [./replacer \"NULL\" \"123\" \"\"]"
echo "cat NULL:"
cat NULL
echo " "

./replacer "NULL" "123" ""

echo "cat NULL.replace:"
cat NULL.replace
echo "############################################"


echo "TEST SI S1 APPARAIT DANS S2: [./replacer \"tricks\" \"123\" \"1234\"]"
echo "cat tricks:"
cat tricks
echo ""

./replacer "tricks" "123" "1234"

echo "cat tricks.replace:"
cat tricks.replace
echo "############################################"
