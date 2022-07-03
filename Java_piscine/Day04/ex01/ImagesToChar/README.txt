# HOW TO USE:  ./README.txt (or sh README.txt)

rm -fr target

mkdir target

# flag -d - where place to .class files (куда поместить .class файлы)
javac `find . -name "*.java"` -d target

cp -R src/resources target/

# c - create archive, f - file name, m - include manifest file
# follow - a list of entered files
# -C - change directory and include following file
jar -cfm ./target/images-to-chars-printer.jar src/manifest.txt -C target .

# дать права на исполнение
chmod u+x ./target/images-to-chars-printer.jar

# разархивировать jar файл
java -jar target/images-to-chars-printer.jar . 0