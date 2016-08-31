#include <vector>

#include "crpropa/Module.h"

namespace crpropa {

/**
 @class ParticleContainerOutput
 @brief A helper ouput mechanism to directly transfer candidates to Python
 */
class ParticleContainerOutput: public Module {
protected:
        typedef std::vector<ref_ptr<Candidate> > tContainer;
        mutable tContainer container;
        std::size_t nBuffer;

public:
        ParticleContainerOutput(std::size_t size = 1e6);
        ~ParticleContainerOutput();

        void process(Candidate *candidate) const;
        std::size_t getCount() const;
	ref_ptr<Candidate> operator[](const std::size_t i) const;
        void clearContainer();
        std::string getDescription() const;
	std::vector<ref_ptr<Candidate> > getAll() const;

	// iterator goodies
        typedef tContainer::iterator iterator;
        typedef tContainer::const_iterator const_iterator;
        iterator begin();
        const_iterator begin() const;
        iterator end();
        const_iterator end() const;
};

} // namespace crpropa
