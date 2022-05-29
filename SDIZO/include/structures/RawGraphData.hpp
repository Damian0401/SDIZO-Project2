#pragma once

namespace SDIZO
{
	struct RawGraphData
	{
		RawGraphData(const RawGraphData& rawGraphData)
			: data(rawGraphData.data), vertexNumber(rawGraphData.vertexNumber), 
			edgeNumber(rawGraphData.edgeNumber) {}

		RawGraphData() : data(nullptr), vertexNumber(0), edgeNumber(0) {}

		size_t* data;
		size_t vertexNumber;
		size_t edgeNumber;
	};
}