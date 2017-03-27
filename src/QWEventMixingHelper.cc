#include "QWAna/QWHelper/interface/QWEventMixingHelper.hh"


QWEventMixingHelper::QWEventMixingHelper( std::vector<double> pz, std::vector<double> pCent, int dept) :
		pz_(pz),
		pCent_(pCent),
		dept_(dept)
{
	Nvz_ = pz_.size() -1 ;
	Ncent_ = pCent_.size() -1;
	mix.reserve(Nvz_);
}

int QWEventMixingHelper::push(double vz, double cent, MEvent evt)
{
	int vzdis = std::distance(pz_.begin(), std::lower_bound(pz_.begin(), pz_.end(), vz)) - 1;
	if ( vzdis < 0 or vzdis >= Nvz_ ) return -1;

	int centdis = std::distance(pCent_.begin(), std::lower_bound(pCent_.begin(), pCent_.end(), cent)) - 1;
	if ( centdis < 0 or centdis >= Ncent_ ) return -2;

	if ( mix[vzdis][centdis].size() >= dept_ ) {
		mix[vzdis][centdis].pop_front();
		mix[vzdis][centdis].push_back(evt);
	} else {
		mix[vzdis][centdis].push_back(evt);
	}
	return mix[vzdis][centdis].size();
}

QWEventMixingHelper::vEvent* QWEventMixingHelper::get(double vz, double cent)
{
	int vzdis = std::distance(pz_.begin(), std::lower_bound(pz_.begin(), pz_.end(), vz)) - 1;
	if ( vzdis < 0 or vzdis >= Nvz_ ) return nullptr;

	int centdis = std::distance(pCent_.begin(), std::lower_bound(pCent_.begin(), pCent_.end(), cent)) - 1;
	if ( centdis < 0 or centdis >= Ncent_ ) return nullptr;

	return &mix[vzdis][centdis];
}
