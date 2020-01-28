const Random = require("random-js")
var frames = []
var n = 5;
var out_frames = []
var out_frames_push = function(str){
  let new_dot_src = frames.join('\n') + str + "}"
  out_frames.push({
    dot_src:new_dot_src
  })
}

function push_frames(){
  let t = []
  /* 得到每个点的颜色 */
  for(let i =1 ;i<=10;i++){
    if( Col[i])
      t.push(`${i}[color="${Col[i] == 1 ? 'red' : 'blue'}"];`)
  }
  out_frames_push(t.join('\n'))
}

const maxn=11;
var Col = new Array(maxn).fill(0);  //颜色
var Ans = new Array(maxn).fill(0);  //颜色
var cnt = 0;
var e = new Array(maxn)
for( let i = 0;i< e.length;i++)
  e[i] = new Array()

function oth(x){ return x % 2 == 0 ? x-1 : x+1; }

//染色
function Paint( x ){
  if( Col[x] != 0 )
    return Col[x] % 2;
  Col[x] = 1; Col[oth(x)] = 2;
  Ans[++cnt] = x;
  for( let i = 0;i< e[x].length; i ++){
    if( !Paint(e[x][i]))
        return false;
  }
  return true;
}

function Work(){
  for( let i =1;i<=n*2;i+=2){
    if( Col[i] ) continue;
    cnt = 0;
    if( !Paint(i)){
      push_frames()
      for( let j = 1;j<=cnt; j++){
        Col[Ans[j]] = Col[oth(Ans[j])] = 0;
      }
      push_frames()
      if( !Paint(oth(i))){
        push_frames()
        return false;
      }
    }
  }
  return true;
}


/*  数据生成 */
var gen_data = function(){
  frames = []
  const print = function(x) { frames.push(x)}
  var log = console.log
  const random = new Random.Random( Random.MersenneTwister19937.autoSeed())

  function randint(minNum,maxNum){ 
    return random.integer(minNum,maxNum)
  } 

  let a =[ ]
  let m = randint(2, 5)
  log("数据如下:")
  log(5,m)
  for(let i = 0;i<m;i++){
    while(1){
      let u = randint(1, 10);
      let v = randint(1, 10);
      if( u == v ||  u == oth(v)) continue;
      a.push([u,v])
      log(u,v)
      break;
    }
  }
  for( let ain of a ){
    let [u,v] = ain
    e[u].push( oth(v)); //数据存入
    e[v].push( oth(u));
  }



  let temp_start = `
digraph g {
    node[shape=circle fixedsize=true style=filled fillcolor=white colorscheme=accent8 ];
    1-> 3-> 5-> 7-> 9[style=invis];
    2-> 4-> 6-> 8-> 10[style=invis];
    1->2[constraint=false minlen=3 style=invis];
`
  print(temp_start)
  for( let l of a ){
    if( l[0] === oth(l[1])) continue;
    if( l[0] === l[1]) continue;
    print( `${l[0]}->${oth(l[1])}[constraint=false];`)
    print( `${l[1]}->${oth(l[0])}[constraint=false];`)
  }
  //print('}')
  out_frames.push("")
  if( Work()){
    for( let i = 1;i<=n*2; i++){
      if( Col[i] == 1)
        console.log(i)
    }
  }
  else
    console.log("NIE")


  //return {
    //frames:[
      //{
        //dot_src: frames.join("\n"),
        //log:'随机生成数据,用于理解,具体数据见[控制台]'
      //}
    //]
  //}
}
gen_data()
