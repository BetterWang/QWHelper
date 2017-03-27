
// Mixing event helper class
// events are sorted in vz and centrality ranges
//

#include <vector>
#include <list>

class QWEventMixingHelper {
public:
	explicit QWEventMixingHelper(std::vector<double> pz,
			std::vector<double> pCent,
			int	dept);
	struct MEvent {
		std::vector<double>	phi;
		std::vector<double>	eta;
		std::vector<double>	pT;
		std::vector<double>	weight;
	};
	typedef	std::list<MEvent>	vEvent;

	int	push(double, double, MEvent);
	vEvent*	get(double, double);

private:
	int	Nvz_;
	int	Ncent_;
	std::vector<double>	pz_;
	std::vector<double>	pCent_;
	unsigned int const	dept_;

	// vEvent mix[Nvz][Ncent];
	std::vector< std::vector< vEvent > >	mix;
};

