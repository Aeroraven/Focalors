using System;

public class Solution
{
	const double START_LEARNING_RATE = 1, EPSILON = 1e-7, DECAY = 0.999;

	public double GetMinDistSum(int[][] positions)
	{
		double learningRate = START_LEARNING_RATE;
		double xMin = int.MaxValue, yMin = int.MaxValue, xMax = int.MinValue, yMax = int.MinValue;
		foreach (int[] position in positions)
		{
			int x = position[0], y = position[1];
			xMin = Math.Min(xMin, x);
			yMin = Math.Min(yMin, y);
			xMax = Math.Max(xMax, x);
			yMax = Math.Max(yMax, y);
		}
		Random random = new Random();
		double xCentre = xMin + random.NextDouble() * (xMax - xMin);
		double yCentre = yMin + random.NextDouble() * (yMax - yMin);
		bool flag = true;
		while (flag)
		{
			double dx = 0, dy = 0;
			foreach (int[] position in positions)
			{
				int x = position[0], y = position[1];
				dx += 2 * (xCentre - x) / (Math.Sqrt((xCentre - x) * (xCentre - x) + (yCentre - y) * (yCentre - y)) + EPSILON);
				dy += 2 * (yCentre - y) / (Math.Sqrt((xCentre - x) * (xCentre - x) + (yCentre - y) * (yCentre - y)) + EPSILON);
			}
			double distance = GetEuclideanDistance(xCentre, yCentre, xCentre + dx, yCentre + dy);
			xCentre -= learningRate * dx;
			yCentre -= learningRate * dy;
			learningRate *= DECAY;
			if (distance < EPSILON)
			{
				flag = false;
			}
		}
		double minDistSum = 0;
		foreach (int[] position in positions)
		{
			minDistSum += GetEuclideanDistance(xCentre, yCentre, position[0], position[1]);
		}
		return minDistSum;
	}

	public double GetEuclideanDistance(double x1, double y1, double x2, double y2)
	{
		return Math.Sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
	}
}