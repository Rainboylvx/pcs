import MyDb  from '../../lib/db.js'
import info_headers from 'virtual:blogData';


const my_db = new MyDb()

my_db.reload(info_headers)

export default my_db
