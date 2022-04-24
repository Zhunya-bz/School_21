rm -fr target

mkdir target

#flag -d - where place to .class files
javac src/java/edu.school21.printer/*/*.java -d target

java -classpath ./target edu.school21.printer.app.Program . 0 /Users/saltmer/Downloads/it.bmp