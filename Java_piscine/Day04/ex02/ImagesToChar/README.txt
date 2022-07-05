# HOW TO USE:  ./README.txt (or sh README.txt)

rm -fr target

mkdir target

# -extract files, .jar file, files to extract (find all .class files)
jar -xf lib/jcommander-1.78.jar `jar -tf lib/jcommander-1.78.jar | grep '\.class'`
mv com target/

jar -xf lib/JCDP-2.0.3.1.jar `jar -tf lib/JCDP-2.0.3.1.jar | grep '\.class'`
cp -R com target/
rm -fr com

# flag -d - where place to .class files (куда поместить .class файлы)
javac -cp .:lib/JCDP-2.0.3.1.jar:lib/jcommander-1.78.jar `find . -name "*.java"` -d target

cp -R src/resources target/

# c - create archive, f - file name, m - include manifest file
# follow - a list of entered files
# -C - change directory and include following file
jar -cfm ./target/images-to-chars-printer.jar src/manifest.txt -C target .


# дать права на исполнение
chmod u+x ./target/images-to-chars-printer.jar

# разархивировать jar файл
java -jar target/images-to-chars-printer.jar --white=RED --black=GREEN