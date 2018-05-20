javac -cp .;.. GenerateMatr.java
javac -cp .;.. Matr.java
javac -cp .;.. Matrixs.java
cd Matrixes
javac -cp .;.. Matrix.java
javac -cp .;.. MultThread.java
cd ..
@REM jar cmf META-INF\manifest.mf %*
jar cmf META-INF\manifest.mf Matrixes.jar Matrixs.class Matr.class Matrixes\Matrix.class