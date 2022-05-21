#pragma once
#include <GL/glut.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

int** temper;
int* result;
int*** matrix;
const int mSize = 20;

template<class T>
class Graph
{
	vector<T> vertList;
	vector<T> labelList;
	bool* visitedVerts = new bool[vertList.size()];

public:
	int Matrix_temp[mSize][mSize] = { 0 };
	Graph();
	~Graph();
	void DrawGraph();
	void InsertEdge(const T& vertex1, const T& vertex2, int weight);
	void InsertVertex(const T& vertex);
	void DeleteVertex();
	int GetVertPos(const T& vertex);
	int GetAmountVerts();
	int GetAmountEdges();
	int GetWeight(const T& vertex1, const T& vertex2);
	bool Empty();
	bool Full();
	vector<T> GetNeighbors(const T& vertex);
	void Print();
};

int amountVerts;
int winW;
int winH;
int n;
int R;
struct VertCoord
{
	int x, y;
};

VertCoord vertC[20];
Graph <int> graph;

void Prep(int***& matrix, int& n, int**& temper, int*& result)
{
	n = amountVerts;
	temper = new int* [n];
	result = new int[n];
	matrix = new int** [n];
	for (int i = 0; i <= n; i++)
	{
		temper[i] = new int[n];
	}
	for (int i = 0; i < n; i++)
	{
		matrix[i] = new int* [n];
		for (int j = 0; j < n; j++)
		{
			if (graph.Matrix_temp[i][j] == 0)
			{
				matrix[i][j] = nullptr;
				continue;
			}
			matrix[i][j] = new int(graph.Matrix_temp[i][j]);
		}
	}
}

void Answer(int*** matrix, int n, int** temper, int* path)
{
	for (int l = 0; l < n; l++)
	{
		for (int i = 0; i < n; i++)
		{
			int min = 1000000;
			for (int j = 0; j < n; j++)
			{
				if (matrix[i][j] && min > *matrix[i][j])
				{
					min = *matrix[i][j];
				}
			}
			for (int j = 0; j < n; j++)
			{
				if (matrix[i][j])
				{
					*matrix[i][j] -= min;
				}
			}
		}
		for (int j = 0; j < n; j++)
		{
			int min = 1000000;
			for (int i = 0; i < n; i++)
			{
				if (matrix[i][j] && min > *matrix[i][j])
				{
					min = *matrix[i][j];
				}
			}
			for (int i = 0; i < n; i++)
			{
				if (matrix[i][j]) {
					*matrix[i][j] -= min;
				}
			}
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				temper[i][j] = 0;
			}
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (matrix[i][j] && !*matrix[i][j])
				{
					int hmin = 1000000;
					int vmin = 1000000;
					for (int l = 0; l < n; l++)
					{
						if (l != i && matrix[l][j] && hmin > *matrix[l][j])
							hmin = *matrix[l][j];
					}
					for (int l = 0; l < n; l++)
					{
						if (l != j && matrix[i][l] && vmin > *matrix[i][l])
							vmin = *matrix[i][l];
					}
					temper[i][j] = hmin + vmin;
				}
			}
		}
		int mc = 0, mi = 0, mj = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (matrix[i][j] && mc < temper[i][j])
				{
					mc = temper[i][j];
					mi = i;
					mj = j;
				}
			}
		}
		path[mi] = mj;
		for (int i = 0; i < n; i++)
		{
			matrix[i][mj] = nullptr;
		}
		for (int i = 0; i < n; i++)
		{
			matrix[mi][i] = nullptr;
		}
		matrix[mj][mi] = nullptr;
	}
}


void Result(int*** matrix, int n, int** temper, int* result)
{
	Prep(matrix, n, temper, result);
	int s = 0;
	Answer(matrix, n, temper, result);
	cout << "\nОтрезки путей: ";
	for (int i = 0, j = 0; i < n; i++)
	{
		j = result[i];
		cout << i + 1 << " -> " << j + 1 << '\t';
		s += graph.Matrix_temp[i][j];
	}
	cout << endl;
	cout << "\nКратчайший путь: ";
	int temp = 0;
	for (int l = 0; l < n;)
	{
		for (int i = 0, j = 0; i < n; i++)
		{
			if (temp == 0 || i + 1 == temp)
			{
				if (temp == 0) cout << i + 1;
				j = result[i];
				temp = j + 1;
				if (temp > 0)	cout << " -> " << temp;
				l++;
			}
		}
	}
	cout << "\nРасстояние: " << s;
	cout << endl;
}


template<class T>
vector<T> Graph<T>::GetNeighbors(const T& vertex)
{
	vector<T> NeighborsList;
	int vertPos = this->GetVertPos(vertex);
	if (vertPos != (-1))
	{
		for (int i = 0, vertListSize = this->vertList.size(); i < vertListSize; ++i)
		{
			if (this->Matrix_temp[vertPos][i] != 0 && this->Matrix_temp[i][vertPos] != 0)
			{
				NeighborsList.push_back(this->vertList[i]);
			}
		}
	}
	return NeighborsList;
}



template<class T>
void Graph<T>::InsertVertex(const T& vertex)
{
	if (!this->Full())
	{
		this->vertList.push_back(vertex);
	}
	else {
		cout << "Граф заполнен. Невозможно добавить новую вершину " << endl;
		return;
	}
}

template<class T>
void Graph<T>::DeleteVertex()
{
	this->vertList.pop_back();
}


template<class T>
int Graph<T>::GetAmountEdges()
{
	int amount = 0;
	if (!this->Empty())
	{
		for (int i = 0, vertListSize = this->vertList.size(); i < vertListSize; ++i)
		{
			for (int j = 0; j < vertListSize; ++j)
			{
				if (this->Matrix_temp[i][j] == this->Matrix_temp[j][i] && this->Matrix_temp[i][j] != 0)
				{
					amount += 1;
				}
			}
		}
		return (amount / 2);
	}
	else
		return 0;
}

template<class T>
int Graph<T>::GetWeight(const T& vertex1, const T& vertex2)
{
	if (!this->Empty())
	{
		int vertPos1 = GetVertPos(vertex1);
		int vertPos2 = GetVertPos(vertex2);
		return Matrix_temp[vertPos1][vertPos2];
	}
	return 0;
}

template<class T>
int Graph<T>::GetAmountVerts()
{
	return this->vertList.size();
}

template<class T>
bool Graph<T>::Empty()
{
	if (this->vertList.size() != 0)
	{
		return false;
	}
	else
		return true;
}

template<class T>
bool Graph<T>::Full()
{
	return (vertList.size() == mSize);
}

template <class T>
int Graph<T>::GetVertPos(const T& vertex)
{
	for (int i = 0; i < this->vertList.size(); ++i)
	{
		if (this->vertList[i] == vertex)
		{
			return i;
		}
	}
	return -1;
}

template<class T>
Graph<T>::Graph()
{
	for (int i = 0; i < mSize; ++i)
	{
		for (int j = 0; j < mSize; ++j)
		{
			this->Matrix_temp[i][j] = 0;
		}
	}
}

template<class T>
Graph<T>::~Graph()
{
}


Graph <int> MakeGraph()
{
	Graph <int> graph;
	int amountEdges, sourceVertex, targetVertex, edgeWeight;
	cout << "Введите количество вершин графа: "; cin >> amountVerts; cout << endl;
	cout << "Введите количество ребер графа: "; cin >> amountEdges; cout << endl;
	for (int i = 1; i <= amountVerts; ++i)
	{
		int* vertPtr = &i;
		graph.InsertVertex(*vertPtr);
	}
	for (int i = 0; i < amountEdges; ++i)
	{
		cout << "Исходная вершина: "; cin >> sourceVertex; cout << endl;
		int* sourceVertPtr = &sourceVertex;
		cout << "Конечная вершина: "; cin >> targetVertex; cout << endl;
		int* targetVertPtr = &targetVertex;

		cout << "Вес ребра: "; cin >> edgeWeight; cout << endl;
		graph.InsertEdge(*sourceVertPtr, *targetVertPtr, edgeWeight);
	}
	cout << endl;
	return graph;
}

template<class T>
void Graph<T>::InsertEdge(const T& vertex1, const T& vertex2, int weight)
{
	if (this->GetVertPos(vertex1) != (-1) && this->GetVertPos(vertex2) != (-1))
	{
		int vertPos1 = GetVertPos(vertex1);
		int vertPos2 = GetVertPos(vertex2);
		if (this->Matrix_temp[vertPos1][vertPos2] != 0 && this->Matrix_temp[vertPos2][vertPos1] != 0)
		{
			cout << "Ребро между вершинами уже есть" << endl;
			return;
		}
		else
		{
			this->Matrix_temp[vertPos1][vertPos2] = weight;
			this->Matrix_temp[vertPos2][vertPos1] = weight;
		}
	}
	else
	{
		cout << "Обеих вершин (или одной из них) нет в графе " << endl;
		return;
	}
}

template<class T>
void Graph<T>::Print()
{
	if (!this->Empty())
	{
		cout << "Матрица смежности графа: " << endl;
		for (int i = 0, vertListSize = this->vertList.size(); i < vertListSize; ++i)
		{
			cout << this->vertList[i] << " ";
			for (int j = 0; j < vertListSize; ++j)
			{
				cout << " " << this->Matrix_temp[i][j] << " ";
			}
			cout << endl;
		}

	}

}

void SetCoord(int i, int n)
{
	int Rtemp;
	int x0 = winW / 2;
	int y0 = winH / 2;
	if (winW > winH)
	{
		R = 5 * (winH / 13) / n;
		Rtemp = winH / 2 - R - 10;
	}
	else
	{
		R = 5 * (winW / 13) / n;
		Rtemp = winW / 2 - R - 10;
	}
	float theta = 2.0f * 3.1415926f * float(i) / float(n);
	float y1 = Rtemp * cos(theta) + y0;
	float x1 = Rtemp * sin(theta) + x0;
	vertC[i].x = x1;
	vertC[i].y = y1;
}

void DrawCircle(int x, int y, int R)
{
	glColor3f(1.0f, 1.0f, 1.0f);
	float x1, y1;
	glBegin(GL_POLYGON);
	for (int i = 0; i < 360; i++)
	{
		float theta = 2.0f * 3.1415926f * float(i) / float(360);
		y1 = R * cos(theta) + y;
		x1 = R * sin(theta) + x;;
		glVertex2f(x1, y1);
	}
	glEnd();
	glColor3f(0.1f, 0.1f, 0.1f);
	float x2, y2;
	glBegin(GL_LINE_LOOP);
	for (int i = 0; i < 360; i++)
	{
		float theta = 2.0f * 3.1415926f * float(i) / float(360);
		y2 = R * cos(theta) + y;
		x2 = R * sin(theta) + x;
		glVertex2f(x2, y2);
	}
	glEnd();
}

void DrawText(int nom, int x1, int y1)
{
	GLvoid* font = GLUT_BITMAP_HELVETICA_18;
	string s = to_string(nom);
	glRasterPos2i(x1 - 5, y1 - 5);
	for (int j = 0; j < s.length(); j++)
	{
		glutBitmapCharacter(font, s[j]);
	}
}

void DrawVertex(int n)
{
	for (int i = 0; i < n; i++)
	{
		DrawCircle(vertC[i].x, vertC[i].y, R);
		DrawText(i + 1, vertC[i].x, vertC[i].y);
	}
}

void DrawLine(int text, int x0, int y0, int x1, int y1)
{
	glClearColor(0.0, 0.0, 1.0, 0.0);
	glBegin(GL_LINES);
	glVertex2i(x0, y0);
	glVertex2i(x1, y1);
	glEnd();
	DrawText(text, (x0 + x1) / 2 + 10, (y0 + y1) / 2 + 10);
}


template<class T>
void Graph<T>::DrawGraph()
{
	int n = vertList.size();
	for (int i = 0; i < n; i++)
	{
		SetCoord(i, n);
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			int a = Matrix_temp[i][j];
			if (a != 0)
			{
				DrawLine(a, vertC[i].x, vertC[i].y, vertC[j].x, vertC[j].y);
			}
		}
	}
	DrawVertex(n);
}

void Change(int w, int h)
{
	winW = w;
	winH = h;
	glViewport(0, 0, (GLsizei)winW, (GLsizei)winH);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, (GLdouble)winW, 0, (GLdouble)winH);
	glutPostRedisplay();
}

void DrawMenuText(string text, int x1, int y1)
{
	GLvoid* font = GLUT_BITMAP_HELVETICA_18;
	string s = text;
	glRasterPos2i(x1, y1);
	for (int j = 0; j < s.length(); j++)
	{
		glutBitmapCharacter(font, s[j]);
	}
}

void DrawMenu()
{
	int height = winH;

	glColor3f(0.4f, 0.8f, 0.5f);
	glBegin(GL_QUADS);
	glVertex2i(10, winH - 50);
	glVertex2i(10, winH - 100);
	glVertex2i(150, winH - 100);
	glVertex2i(150, winH - 50);
	glEnd();
	glColor3d(0, 0, 0);
	DrawMenuText("Add vertex", 30, winH - 80);

	glColor3f(0.4f, 0.8f, 0.5f);
	glBegin(GL_QUADS);
	glVertex2i(10, winH - 150);
	glVertex2i(10, winH - 200);
	glVertex2i(150, winH - 200);
	glVertex2i(150, winH - 150);
	glEnd();
	glColor3d(0, 0, 0);
	DrawMenuText("Delete vertex", 25, winH - 180);


	glColor3f(0.4f, 0.8f, 0.5f);
	glBegin(GL_QUADS);
	glVertex2i(10, winH - 250);
	glVertex2i(10, winH - 300);
	glVertex2i(150, winH - 300);
	glVertex2i(150, winH - 250);
	glEnd();
	glColor3d(0, 0, 0);
	DrawMenuText("Matrix", 50, winH - 280);

	glColor3f(0.4f, 0.8f, 0.5f);
	glBegin(GL_QUADS);
	glVertex2i(10, winH - 350);
	glVertex2i(10, winH - 400);
	glVertex2i(150, winH - 400);
	glVertex2i(150, winH - 350);
	glEnd();
	glColor3d(0, 0, 0);
	DrawMenuText("Result", 50, winH - 380);

	glColor3f(0.4f, 0.8f, 0.5f);
	glBegin(GL_QUADS);
	glVertex2i(10, winH - 450);
	glVertex2i(10, winH - 500);
	glVertex2i(150, winH - 500);
	glVertex2i(150, winH - 450);
	glEnd();
	glColor3d(0, 0, 0);
	DrawMenuText("New Graph", 35, winH - 480);
}

void MouseClick(int btn, int stat, int x, int y)
{
	if (stat == GLUT_DOWN)
	{
		if (x > 10 && x < 150 && y >  50 && y < 100)
		{
			int sourceVertex;
			int targetVertex;
			int edgeWeight;
			cout << "Исходная вершина: "; cin >> sourceVertex; cout << endl;
			int* sourceVertPtr = &sourceVertex;
			cout << "Конечная вершина: "; cin >> targetVertex; cout << endl;
			int* targetVertPtr = &targetVertex;
			if (sourceVertex > amountVerts || targetVertex > amountVerts)
			{
				amountVerts++;
				int* vertPtr = &amountVerts;
				graph.InsertVertex(*vertPtr);
			}
			cout << "Вес ребра: "; cin >> edgeWeight; cout << endl;
			graph.InsertEdge(*sourceVertPtr, *targetVertPtr, edgeWeight);
		}
		if (x > 10 && x < 150 && y > 150 && y < 200)
		{
			int sourceVertex;
			int targetVertex;
			int edgeWeight;
			cout << "Введите вершину: "; cin >> sourceVertex; cout << endl;
			int* sourceVertPtr = &sourceVertex;
			if (sourceVertex == amountVerts)
			{
				amountVerts--;
				graph.DeleteVertex();
			}
			else cout << "Невозможно удалить вершину \n";
		}
		if (x > 10 && x < 150 && y >  250 && y < 300)
		{
			graph.Print();
		}
		if (x > 10 && x < 150 && y >  350 && y < 400)
		{
			Result(matrix, n, temper, result);
		}
		if (x > 10 && x < 150 && y >  450 && y < 500)
		{
			graph = MakeGraph();
		}
	}
	glutPostRedisplay();
}

void Display()
{
	glShadeModel(GL_SMOOTH);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, winW, 0, winH);
	glViewport(0, 0, winW, winH);
	glClearColor(1.0, 1.0, 0.6, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);

	graph.DrawGraph();
	DrawMenu();
	glutSwapBuffers();
}

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "RUS");
	glutInit(&argc, argv);
	graph = MakeGraph();
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(900, 600);
	glutCreateWindow("Graph");
	winW = glutGet(GLUT_WINDOW_WIDTH);
	winH = glutGet(GLUT_WINDOW_HEIGHT);
	glutDisplayFunc(Display);
	glutReshapeFunc(Change);
	glutMouseFunc(MouseClick);
	glutMainLoop();
	return 0;
}