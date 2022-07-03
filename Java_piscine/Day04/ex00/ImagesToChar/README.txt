# HOW TO USE:  ./README.txt (or sh README.txt)

rm -fr target

mkdir target

# flag -d - where place to .class files (куда поместить .class файлы)
javac src/java/edu.school21.printer/*/*.java -d target

# По существу classpath указывает компилятору или виртуальной машине где искать классы необходимые для сборки проекта или же его запуска.
# ./target - папка где нужно искать
# далее идет запускаемый файл (с именем пакета)
# следом - 3 аргумента для запуска ( . - белый, 0 - черный, путь до картинки)
java -classpath ./target edu.school21.printer.app.Program . 0 ~/Downloads/it.bmp