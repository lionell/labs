package Matrixes;

import java.io.*;
import java.util.Random;

public class Matrix implements java.io.Serializable
{
  private float mfMatrix[][];
  private int mHeight;
  private int mWidth;

  public Matrix(String filename){ Load(filename); }
  public Matrix(int iHeight, int iWidth)
  {
    mHeight = iHeight;
    mWidth = iWidth;
    mfMatrix = new float[mHeight][mWidth];
  }

  public void SetItem(int y, int x, float fValue)
  {
    mfMatrix[y][x] = fValue;
  }

  public float Item(int y, int x)
  {
    return mfMatrix[y][x];
  }

  public Matrix SubMatrix(int iTop, int iLeft, int iHeight, int iWidth)
  {
    Matrix mSubMatrix;
    int iX, iY;
    //System.out.println(iTop + " " + iHeight + " " + mHeight);
    //System.out.println(iLeft + " " + iWidth + " " + mWidth);
    if ((iTop >=0) && (iLeft >=0) && (iTop + iHeight <= mHeight) && (iLeft + iWidth <= mWidth))
    {
      mSubMatrix = new Matrix(iHeight, iWidth);
      for (iY = 0; iY < iHeight; iY++)
      {
        for (iX = 0; iX < iWidth; iX++)
        {
          mSubMatrix.SetItem(iY, iX, mfMatrix[iTop + iY][iLeft + iX]);
        }
      }
    } else
    {
      mSubMatrix = null;
    }
    return mSubMatrix;
  }

  public int Height()
  {
    return mHeight;
  }

  public int Width()
  {
    return mWidth;
  }

  public void Add(Matrix mMatrix)
  {
    int iX, iY;
    //If Matrix mMatrix has the same dimensions, perform addition
    if ((mMatrix.Height() == this.Height()) && (mMatrix.Width() == this.Width()))
    {
      for (iY = 0; iY < mHeight; iY++)
      {
        for (iX = 0; iX < mWidth; iX++)
        {
          mfMatrix[iY][iX] = mfMatrix[iY][iX] + mMatrix.Item(iY, iX);
        }
      }
    }
  }

  public void Assign(Matrix mMatrix)
  {
    int iY, iX;

    mHeight = mMatrix.Height();
    mWidth = mMatrix.Width();
    mfMatrix = new float[mHeight][mWidth];

    for (iY = 0; iY < mHeight; iY++)
    {
      for (iX = 0; iX < mWidth; iX++)
      {
        mfMatrix[iY][iX] = mMatrix.Item(iY, iX);
      }
    }
  }

  public void MultiplyBy(Matrix mMatrix)
  {
    Matrix mResultMatrix;
    int newX, newY, iPos;
    //If multiplier is correct, perform multiplication
    if (this.Width() == mMatrix.Height())
    {
      mResultMatrix = new Matrix(mHeight, mMatrix.Width());
      for (newY = 0; newY < mHeight; newY++)
      {
        //The next line is for debugging purposes only
        //System.out.println(this.toString());
        for (newX = 0; newX < mMatrix.Width(); newX++)
        {
          mResultMatrix.SetItem(newY, newX, 0);
          for (iPos = 0; iPos < mWidth; iPos++)
          {
            mResultMatrix.SetItem(newY, newX, mResultMatrix.Item(newY, newX) + mfMatrix[newY][iPos] * mMatrix.Item(iPos, newX));
          }
        }
      }
      this.Assign(mResultMatrix);
    }
  }

  public void Save(String sFileName)
  {
    try
    {
      FileOutputStream file = new FileOutputStream(sFileName);
      ObjectOutputStream out = new ObjectOutputStream(file);
      out.writeObject(this);
      out.flush();
      out.close();
    }
    catch (java.io.IOException e)
    {
      System.out.println("Can not save file "+sFileName+": "+e);
    }
  }

  public void Load(String sFileName)
  {
    Matrix mInMatrix;

    try
    {
      FileInputStream file = new FileInputStream(sFileName);
      ObjectInputStream in = new ObjectInputStream(file);
      mInMatrix = (Matrix)in.readObject();
      in.close();
      this.Assign(mInMatrix);
    }
    catch (java.io.IOException e)
    {
      System.out.println("Can not load file "+sFileName+": "+e);
    }
    catch (java.lang.ClassNotFoundException CNFE)
    {
      System.out.println("Class is not found in the specified file");
    }
  }

  public void RandomFill(int iMaxValue)
  {
    Random rand;
    int iY, iX;

    rand = new Random();

    for (iY = 0; iY < mHeight; iY++)
    {
      for (iX = 0; iX < mWidth; iX++)
      {
        mfMatrix[iY][iX] = rand.nextInt(iMaxValue);
      }
    }
  }

  public void SystemOutput()
  {
    int iY, iX;

    for (iY = 0; iY < mHeight; iY++)
    {
      System.out.println("");
      for (iX = 0; iX < mWidth; iX++)
      {
        System.out.print(new Float(mfMatrix[iY][iX]).toString() + "  ");
      }
    }
  }

  public void FillSubMatrix(Matrix mSource, int iTop, int iLeft)
  {
    int iY, iX;
    if ((iTop + mSource.Height() <= mHeight) && (iLeft + mSource.Width() <= mWidth))
    {
      for (iY = 0; iY < mSource.Height(); iY++)
      {
        for (iX = 0; iX < mSource.Width(); iX++)
        {
          mfMatrix[iTop + iY][iLeft + iX] = mSource.Item(iY, iX);
        }
      }
    }
  }
}
