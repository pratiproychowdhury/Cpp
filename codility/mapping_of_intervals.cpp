#include <map>
#include <limits>

template<typename K, typename V>
class interval_map {
	std::map<K,V> m_map;

public:
    // constructor associates whole range of K with val by inserting (K_min, val)
    // into the map
    interval_map( V const& val) {
        m_map.insert(m_map.end(),std::make_pair(std::numeric_limits<K>::lowest(),val));
    }

    // Assign value val to interval [keyBegin, keyEnd).
    // Overwrite previous values in this interval.
    // Conforming to the C++ Standard Library conventions, the interval
    // includes keyBegin, but excludes keyEnd.
    // If !( keyBegin < keyEnd ), this designates an empty interval,
    // and assign must do nothing.
    void assign( K const& keyBegin, K const& keyEnd, V const& val ) {
      
      if (!(keyBegin<keyEnd))
        return;
      
      auto inserted_term = m_map.emplace(keyBegin,val);
      
      if (inserted_term.second == false)
        (inserted_term.first)->second = val;
      
      // Check if the previous term has the same val, if so, delete inserted one
      auto ptrprevious = inserted_term.first;
      if (ptrprevious != m_map.begin()) {
        ptrprevious--;
        if (ptrprevious->second == val) {
          m_map.erase(inserted_term.first);
          return;
        }
      }
      
      // Delete all the mappings in the interval between keyBegin and keyEnd
      auto ptrstart = inserted_term.first;
      ptrstart++;
      auto ptrend = ptrstart;
      if (ptrend == m_map.end())
        return;
      while ((ptrend != m_map.end()) && (ptrend->first < keyEnd))
        ptrend++;
      if (ptrstart != ptrend)
        m_map.erase(ptrstart, ptrend);
      
      // Confirm next key does not have the same value as inserted one
      auto ptrnext = inserted_term.first;
      ptrnext++;
      if ((ptrnext != m_map.end()) && (ptrnext->second == val))
        m_map.erase(ptrnext); 
    }

    // look-up of the value associated with key
    V const& operator[]( K const& key ) const {
        return ( --m_map.upper_bound(key) )->second;
    }
};
