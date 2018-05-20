package Matrixes;

public class MultThread extends Thread
{
  private Matrix mfRes;
  private Matrix mfMultiplier1;
  private Matrix mfMultiplier2;

  public MultThread(Matrix mMultiplier1, Matrix mMultiplier2)
  {
    mfMultiplier1 = mMultiplier1;
    mfMultiplier2 = mMultiplier2;
    mfRes = new Matrix(mMultiplier1.Height(), mMultiplier2.Width());
  }

  public void run()
  {
    mfRes.Assign(mfMultiplier1);
    mfRes.MultiplyBy(mfMultiplier2);
  }

  public Matrix GetResult()
  {
    if (!this.isAlive())
    {
       return mfRes;
    } else
    {
      return null;
    }
  }
}

