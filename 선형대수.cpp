# include<stdio.h>
# include<conio.h>
#pragma warning(disable:4996)
int main() {

	int i, j, k, n, m, c;
	float a[10][10], x[10], temp;
	float s, p;

	printf("Enter the number of equations : ");
	scanf("%d", &n);
	printf("Enter the number of unknown : ");
	scanf("%d", &m);

	printf("\nEnter the co-efficients of the equations :\n\n");
	for (i = 0; i<n; i++)
	{
		for (j = 0; j<m; j++)
		{
			printf("a[%d][%d]= ", i + 1, j + 1);
			scanf("%f", &a[i][j]);
		}
		printf("d[%d]= ", i + 1);
		scanf("%f", &a[i][m]);
	}

	// ù ���� 0�� �ƴ� �� ���� �� ��ȯ���ִ� �Լ� 
	int l = -1;
	while ((l<n)&(a[0][0] == 0)) {
		l++;
		for (int q = 0; q <= m; q++) {
			temp = a[0][q];
			a[0][q] = a[n - 1 - l][q];
			a[n - 1 - l][q] = temp;
		}
	}

	// ��� ������ 0�� �˻�
	for (i = 0; i<n; i++) {
		if ((a[i][0] == 0)&(a[i][1] == 0)&(a[i][2] == 0)&(a[i][3] == 0)) { // 0�̸�
																		   //i��� ������ ���� �ڸ��ٲ�
			for (j = 0; j <= m; j++) {
				temp = a[n - 1][j];
				a[n - 1][j] = a[i][j];
				a[i][j] = temp;
			}
		}
	}
	// �׳� ��� ������ִ� �Լ� 
	for (i = 0; i<n; i++)
	{
		for (j = 0; j<m; j++)
		{
			printf("a[%d][%d]= %f ", i + 1, j + 1, a[i][j]);
		}
		printf("d[%d]= %f ", i + 1, a[i][m]); printf("\n");
		getch();
	}
	// ���콺 �ҰŹ� ����
	for (k = 0; k<n - 1; k++) { //��
		for (i = k + 1; i<n; i++)//
		{
			if (a[k][k] == 0) { // �и� 0�ΰ�� ���� �ٲ��ش�
				for (j = 0; i<m; i++) {
					temp = a[k + 1][j];
					a[k + 1][j] = a[k][j];
					a[k][j] = temp;
				}
			}
			p = a[i][k] / a[k][k];
			for (j = k; j<m + 1; j++) //��
				a[i][j] = a[i][j] - p * a[k][j];
		}
	}
	// ���� �� 0�� �˻�
	for (i = 0; i<n; i++) {
		if ((a[i][0] == 0)&(a[i][1] == 0)&(a[i][2] == 0)&(a[i][3] == 0)) { // 0�̸�i��� ������ ���� �ڸ��ٲ�
			for (j = 0; j <= m; j++) {
				temp = a[n - 1][j];
				a[n - 1][j] = a[i][j];
				a[i][j] = temp;
			}
		}
	}

	// �׳� ��� ������ִ� �Լ�
	for (i = 0; i<n; i++)
	{
		for (j = 0; j<m; j++)
		{
			printf("a[%d][%d]= %f ", i + 1, j + 1, a[i][j]);
		}
		printf("d[%d]= %f ", i + 1, a[i][m]); printf("\n");
		getch();
	}

	for (i = 0; i<n; i++) {
		if ((a[i][0] == 0)&(a[i][1] == 0)&(a[i][2] == 0)&(a[i][3] != 0)) {
			printf("\n�ذ� ����"); getch(); return 0;
		}
	}
	//-------------------------------------------------------------------------------
	if (a[n - 1][m - 1] == 0) {
		printf("x 3 = t\n");
		for (i = n - 2; i >= 0; i--)
		{
			s = 0;
			for (j = i + 1; j<n; j++)
			{
				//
				if (a[i][i] == 0) {}
				else {
					s += (a[i][j]);
					x[i] = (a[i][n] - s) / a[i][i];
				}
			}
		}
		for (int k = 1; k<n - 1; k++) {
			p = a[k - 1][k] / a[k][k];
			for (j = 1; j<m + 1; j++) //��
				a[k - 1][j] = a[k - 1][j] - p * a[k][j];
		}
		printf("\n<result>\n");
		for (i = 0; i<m - 1; i++)
			printf("\nx %d=%f - %ft", i + 1, a[i][n] / a[i][i], a[i][m - 1] / a[i][i]);
		getch();
		printf("\nx 3 = t\n");
	}


	else {
		x[m - 1] = a[n - 1][m] / a[n - 1][m - 1];
		for (i = n - 2; i >= 0; i--)
		{
			s = 0;
			for (j = i + 1; j<n; j++)
			{
				//
				if (a[i][i] == 0) {}
				else {
					s += (a[i][j] * x[j]);
					x[i] = (a[i][n] - s) / a[i][i];
				}
			}
		}
		for (i = 0; i<n; i++)
		{
			for (j = 0; j<m; j++)
			{
				printf("a[%d][%d]= %f ", i + 1, j + 1, a[i][j]);
			}
			printf("d[%d]= %f ", i + 1, a[i][m]); printf("\n");
			getch();

		}
		printf("\n<result>\n");
		for (i = 0; i<m; i++)
			printf("\nx %d=%f", i + 1, x[i]);
		getch();
		return 0;
	}

	for (i = 0; i<n; i++) {
		if ((a[i][0] == 0)&(a[i][1] == 0)&(a[i][2] == 0)&(a[i][3] == 0)) {
			printf("\n�ذ� ������ ����"); getch(); return 0;
			//
		}
	}
}