#pragma once

namespace SDIZO
{
	enum class MatrixCell
	{
		None = 0,
		Origin = -1,
		Destination = 1
	};

	enum class TimerPrecision
	{
		Nanoseconds,
		Microseconds,
		Milliseconds,
		Seconds
	};

	enum class Algorithm
	{
		Prim,
		Kruskal,
		Dijkstra,
		BellmanFord
	};

	enum class GraphRepresentation
	{
		Matrix,
		List
	};
}