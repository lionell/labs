javac -sourcepath .;.. Seriess.java
javac -sourcepath .;.. Exp.java
javac -sourcepath .;.. Arctg.java
javac -sourcepath .;.. Log.java
javac -sourcepath .;.. Cos.java
javac -sourcepath .;.. Sin.java
jar cmf META-INF\manifest.mf Series.jar SeriesS.class Exp.class Arctg.class Log.class Sin.class Cos.class
