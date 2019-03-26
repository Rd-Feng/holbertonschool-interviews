#include "slide_line.h"
int move_left(int *line, int size);
int move_right(int *line, int size);
void merge_left(int *line, size_t size);
void merge_right(int *line, size_t size);
/**
 * slide_line - slide array of integers to the left or right
 * @line: array
 * @size: size of array
 * @direction: direction to slide
 *
 * Return: 1 for success, 0 for failure
 */
int slide_line(int *line, size_t size, int direction)
{
	if ((direction != SLIDE_LEFT && direction != SLIDE_RIGHT) || !line)
		return (0);
	if (direction == SLIDE_LEFT)
		merge_left(line, size);
	else
		merge_right(line, size);
	return (direction == SLIDE_LEFT ?
		move_left(line, size) : move_right(line, size));
}
/**
 * merge_left - merge numbers to left
 * @line: array
 * @size: size
 */
void merge_left(int *line, size_t size)
{
	int i, next;

	for (i = 0, next = 1; next < (int) size;)
	{
		if (!line[i])
		{
			i++;
			next++;
			continue;
		}
		while (next < (int) size && line[next] == 0) /* find next non-zero */
			next++;
		if (next >= (int) size)
			break;
		if (line[i] == line[next])
		{
			line[i] *= 2;
			line[next] = 0;
			i = next + 1;
			next = i + 1;
		}
		else
		{
			i = next;
			next = i + 1;
		}
	}
}
/**
 * merge_right - merge numbers to right
 * @line: array
 * @size: size
 */
void merge_right(int *line, size_t size)
{
	int i, next;

	for (i = (int) size - 1, next = i - 1; next >= 0;)
	{
		if (!line[i])
		{
			i--;
			next--;
			continue;
		}
		while (next >= 0 && line[next] == 0) /* find next non-zero */
			next--;
		if (next < 0)
			break;
		if (line[i] == line[next])
		{
			line[i] *= 2;
			line[next] = 0;
			i = next - 1;
			next = i - 1;
		}
		else
		{
			i = next;
			next--;
		}
	}
}
/**
 * move_left - move numbers to left
 * @line: array
 * @size: size
 *
 * Return: always 1
 */
int move_left(int *line, int size)
{
	int cur, next;

	for (cur = 0, next = 1; cur < size; cur++)
	{
		if (line[cur])
		{
			next++;
			continue;
		}
		while (next < size && line[next] == 0) /* find next number to move */
			next++;
		if (next >= size) /* no more number to move */
			return (1);
		line[cur] = line[next];
		if (cur != next)
			line[next] = 0;
	}
	return (1);
}
/**
 * move_right - move numbers to right
 * @line: array
 * @size: size
 *
 * Return: always 1
 */
int move_right(int *line, int size)
{
	int cur, next;

	for (cur = size - 1, next = cur - 1; cur >= 0; cur--)
	{
		if (line[cur])
		{
			next--;
			continue;
		}
		while (next >= 0 && line[next] == 0) /* find next number to move */
			next--;
		if (next < 0) /* no more number to move */
			return (1);
		line[cur] = line[next];
		if (cur != next)
			line[next] = 0;
	}
	return (1);
}
