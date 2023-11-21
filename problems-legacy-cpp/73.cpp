class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix)
    {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int firstrow = 0;
        int firstcol = 0;
        //��ǵ�һ��
        for (int i = 1; i < cols; i++)
        {
            if (matrix[0][i] == 0)
            {
                firstrow = 1;
            }
        }
        //��ǵ�һ��
        for (int i = 1; i < rows; i++)
        {
            if (matrix[i][0] == 0)
            {
                firstcol = 1;
            }
        }
        //���(0,0)
        if (matrix[0][0] == 0)
        {
            firstcol = firstrow = 1;
        }
        //����������
        for (int i = 1; i < rows; i++)
        {
            for (int j = 1; j < cols; j++)
            {
                if (matrix[i][j] == 0)
                {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;

                }
            }
        }
        //��ճ���һ��֮���������
        for (int i = 1; i < rows; i++)
        {
            if (matrix[i][0] == 0)
            {
                for (int j = 0; j < cols; j++)
                {
                    matrix[i][j] = 0;
                }
            }

        }
        //��յ�һ��֮���������
        for (int i = 1; i < cols; i++)
        {
            if (matrix[0][i] == 0)
            {
                for (int j = 0; j < rows; j++)
                {
                    matrix[j][i] = 0;
                }
            }
        }
        //��յ�һ��
        if (firstrow)
        {
            for (int i = 0; i < cols; i++)
            {
                matrix[0][i] = 0;
            }
        }
        //��յ�һ��
        if (firstcol)
        {
            for (int i = 0; i < rows; i++)
            {
                matrix[i][0] = 0;
            }
        }

    }
};