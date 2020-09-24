
#pragma once
namespace CXXGRAPH
{
	namespace BASESTRUCT
	{
		class Link
		{
		private:
		public:
			Link();
			~Link();

			//Operators
			bool operator< (const Link &b) const;
		};
	} // namespace BASESTRUCT
} // namespace CXXGRAPH