import Fuse from 'fuse.js'
import info_headers from 'virtual:blogData';

const options = {
  // isCaseSensitive: false,
  // includeScore: false,
  // shouldSort: true,
  // includeMatches: false,
  // findAllMatches: false,
  // minMatchCharLength: 1,
  // location: 0,
  // threshold: 0.6,
  // distance: 100,
  // useExtendedSearch: false,
  // ignoreLocation: false,
  // ignoreFieldNorm: false,
  // fieldNormWeight: 1,
  keys: [
    "title",
    "_id",
    "tags"
  ]
};

const fuse = new Fuse(info_headers, options);

export const data_fuzzy_search = (str:string)=>{
    return fuse.search(str)
}
