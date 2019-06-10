"use strict";
var framework;
(function (framework) {
    var FileParser = /** @class */ (function () {
        function FileParser(filename, content) {
            this.filename = filename;
            this.content = [];
            for (var _i = 0, _a = content.split('\n'); _i < _a.length; _i++) {
                var line = _a[_i];
                var words = line.trim().split(new RegExp('\\s+'));
                this.content.push(words);
            }
            this.y = 0;
            this.x = 0;
        }
        FileParser.prototype.isEOF = function () {
            return this.content.length <= this.y;
        };
        FileParser.prototype.getWord = function () {
            if (this.isEOF()) {
                this.reportError('a word expected, but EOF');
            }
            if (this.content[this.y].length <= this.x) {
                this.reportError('a word expected, but newline');
            }
            var word = this.content[this.y][this.x];
            this.x += 1;
            return word;
        };
        FileParser.prototype.getInt = function () {
            var word = this.getWord();
            if (!word.match(new RegExp('^[-+]?[0-9]+$'))) {
                this.reportError("a number expected, but word " + JSON.stringify(this.content[this.y][this.x]));
            }
            return parseInt(word);
        };
        FileParser.prototype.getNewline = function () {
            if (this.isEOF()) {
                this.reportError('newline expected, but EOF');
            }
            this.x = 0;
            this.y += 1;
        };
        FileParser.prototype.unwind = function () {
            if (this.x == 0) {
                this.y -= 1;
                this.x = this.content[this.y].length - 1;
            }
            else {
                this.x -= 1;
            }
        };
        FileParser.prototype.reportError = function (msg) {
            msg = this.filename + ": line " + (this.y + 1) + ": " + msg;
            alert(msg);
            throw new Error(msg);
        };
        return FileParser;
    }());
    framework.FileParser = FileParser;
    var FileSelector = /** @class */ (function () {
        function FileSelector() {
            var _this = this;
            this.inputFile = document.getElementById("inputFile");
            this.outputFile = document.getElementById("outputFile");
            this.reloadButton = document.getElementById("reloadButton");
            this.reloadFilesClosure = function () { _this.reloadFiles(); };
            this.inputFile.addEventListener('change', this.reloadFilesClosure);
            this.outputFile.addEventListener('change', this.reloadFilesClosure);
            this.reloadButton.addEventListener('click', this.reloadFilesClosure);
        }
        FileSelector.prototype.reloadFiles = function () {
            var _this = this;
            if (this.inputFile.files == null || this.inputFile.files.length == 0)
                return;
            loadFile(this.inputFile.files[0], function (inputContent) {
                if (_this.outputFile.files == null || _this.outputFile.files.length == 0)
                    return;
                loadFile(_this.outputFile.files[0], function (outputContent) {
                    _this.inputFile.removeEventListener('change', _this.reloadFilesClosure);
                    _this.outputFile.removeEventListener('change', _this.reloadFilesClosure);
                    _this.reloadButton.classList.remove('disabled');
                    if (_this.callback !== undefined) {
                        _this.callback(inputContent, outputContent);
                    }
                });
            });
        };
        return FileSelector;
    }());
    framework.FileSelector = FileSelector;
    var loadFile = function (file, callback) {
        var reader = new FileReader();
        reader.readAsText(file);
        reader.onloadend = function () {
            callback(reader.result);
        };
    };
})(framework || (framework = {}));
var visualizer;
(function (visualizer) {
    var InputFile = /** @class */ (function () {
        function InputFile(content) {
            var parser = new framework.FileParser('<input-file>', content.trim());
            parser.getWord();
            this.DEFAULT_CPAPCITY = 8;
            this.SECONDS_A_DAY = 86400;
            this.M = parser.getInt();
            this.I = parser.getInt();
            this.P = parser.getInt();
            this.R = parser.getInt();
            this.BL = parser.getInt();
            parser.getNewline();
            this.C = [];
            this.D = [];

            parser.getWord();
            for (let i = 0; i < this.M; ++i) {
                this.C.push(parser.getInt());
            }
            parser.getNewline();

            parser.getWord();
            for (let i = 0; i < this.M; ++i) {
                this.D.push(parser.getInt());
            }
            parser.getNewline();
            
            this.boms = [];
            for (let i = 0; i < this.BL; ++i) {
                parser.getWord();
                var _i = parser.getInt();
                --_i;
                var p = parser.getInt();
                --p;
                var m = parser.getInt();
                --m;
                var s = parser.getInt();
                
                if (this.boms[_i] == undefined) {
                    this.boms[_i] = {};
                    this.boms[_i].p = 0;
                    this.boms[_i].pTom = [];
                    this.boms[_i].pTos = [];
                }
                this.boms[_i].p = Math.max(this.boms[_i].p, p+1);
                this.boms[_i].pTom[p] = m;
                this.boms[_i].pTos[p] = s;

                parser.getNewline();
            }

            this.orders = [];
        
            for (let i = 0; i < this.R; ++i) {
                parser.getWord();
                let r = parser.getInt();
                --r;
                let _i = parser.getInt();
                --_i;
                let e = parser.getInt();
                let d = parser.getInt();
                let q = parser.getInt();
                let pr = parser.getInt();
                this.orders[r] = {};
                this.orders[r].i = _i;
                this.orders[r].e = e;
                this.orders[r].d = d;
                this.orders[r].q = q;
                this.orders[r].pr = pr;
                parser.getNewline();
            }
            if (!parser.isEOF())
                parser.reportError("Too long file.");

        }
        return InputFile;

    }());
    var OutputFile = /** @class */ (function () {
        function OutputFile(content, inputFile) {
            var DEFAULT_CPAPCITY = inputFile.DEFAULT_CPAPCITY;
            var M = inputFile.M;
            var parser = new framework.FileParser('<output-file>', content.trim());
            this.AL = parser.getInt();
            parser.getNewline();
            this.mdToC = [];

            for (let i = 0; i < this.AL; ++i) {
                let m = parser.getInt();
                --m;
                let d = parser.getInt();
                let ac = parser.getInt();
                if (this.mdToC[m] == undefined) this.mdToC[m] = [];
                this.mdToC[m][d] = ac + DEFAULT_CPAPCITY;
                parser.getNewline();
            }

            this.operations = [];
            this.OL = parser.getInt();
            parser.getNewline();
            for (let i = 0; i < this.OL; ++i) {
                let r = parser.getInt();
                --r;
                let p = parser.getInt();
                --p;
                let m = parser.getInt();
                --m;
                let t1 = parser.getInt();
                let t2 = parser.getInt();
                if (this.operations[r] == undefined) {
                    this.operations[r] = {};
                    this.operations[r].t1 = [];
                    this.operations[r].t2 = [];
                    this.operations[r].pTom = [];
                }
                this.operations[r].t1[p] = t1;
                this.operations[r].t2[p] = t2;
                this.operations[r].pTom[p] = m;
                parser.getNewline();
            }

            if (!parser.isEOF())
                parser.reportError("Too long file.");

            for (let m = 0; m < inputFile.M; ++m) {
                if (this.mdToC[m] == undefined) this.mdToC[m] = [];
            }

            var mToPreviousT2 = [];
            var rpToTime = [];

            for (let r = 0; r < inputFile.R; ++r) {
                let prevT2 = 0;
                let i = inputFile.orders[r].i;
                let q = inputFile.orders[r].q;
                rpToTime[r] = [];
                for (let p = 0; p < inputFile.boms[i].p; ++p) {
                    let m = inputFile.boms[i].pTom[p];
                    if (mToPreviousT2[m] == undefined) mToPreviousT2[m] = 0;
                    let t1;
                    if (p == 0) {
                        t1 = Math.max(mToPreviousT2[m], (inputFile.orders[r].e-1)*inputFile.SECONDS_A_DAY);
                    } else {
                        t1 = Math.max(mToPreviousT2[m], prevT2);
                    }

                    let _t1 = t1;
                    
                    let needResourceAmount = q*inputFile.boms[i].pTos[p]*inputFile.D[m];
                    let nDay = parseInt((_t1 + inputFile.SECONDS_A_DAY - 1)/inputFile.SECONDS_A_DAY);
                    let c;
                    if (this.mdToC[m][nDay] == undefined) c = inputFile.DEFAULT_CPAPCITY;
                    else c = this.mdToC[m][nDay];
                    let resourceAmountADay = (nDay*inputFile.SECONDS_A_DAY - _t1) * c; 
                    while (needResourceAmount > resourceAmountADay) {
                        needResourceAmount -= resourceAmountADay;
                        ++nDay;
                        _t1 = (nDay-1)*inputFile.SECONDS_A_DAY;
                        if (this.mdToC[m][nDay] == undefined) c = inputFile.DEFAULT_CPAPCITY;
                        else c = this.mdToC[m][nDay];
                        resourceAmountADay = inputFile.SECONDS_A_DAY * c;   
                    }
                    let t2 = _t1 + parseInt(((needResourceAmount+c-1)/c));

                    
                    rpToTime[r][p] = {};
                    rpToTime[r][p].t1 = t1;
                    rpToTime[r][p].t2 = t2;

                    mToPreviousT2[m] = t2;
                    prevT2 = t2;
                }
            }


            var judge = false;
            for (let r = 0; r < inputFile.R; ++r) {
                let i = inputFile.orders[r].i;
                if (this.operations[r].t1.length != inputFile.boms[i].p) {
                    alert("工程数間違い\nオーダ番号: " + r);
                    judge = true;
                }
                for (let p = 0; p < inputFile.boms[i].p; ++p) {
                    let str = "\nオーダ番号: " + (r+1) + ", 製造工程: " + (p+1);
                    if (rpToTime[r][p].t1 < this.operations[r].t1[p]) {
                        alert("作業を前詰めで割りつけていません。" + str);
                        judge = true;
                    } 
                    if (rpToTime[r][p].t1 > this.operations[r].t1[p]) {
                        alert("製造開始時刻違反" + str);
                        judge = true;
                    }
                    if (rpToTime[r][p].t2 != this.operations[r].t2[p]) {
                        alert("製造時間間違い" + str);
                        judge = true;
                    }
                    if (inputFile.boms[i].pTom[p] != this.operations[r].pTom[p]) {
                        alert("BOM違反" + str);
                        judge = true;
                    }
                    if (judge) break;
                }
                if (judge) break;
            }


            if (judge) {
                if (confirm("正しい製造計画に変更しますか?")) {
                    for (let r = 0; r < inputFile.R; ++r) {
                        let i = inputFile.orders[r].i;
                        for (let p = 0; p < inputFile.boms[i].p; ++p) {
                            this.operations[r].t1[p] = rpToTime[r][p].t1;
                            this.operations[r].t2[p] = rpToTime[r][p].t2;
                            this.operations[r].pTom[p] = inputFile.boms[i].pTom[p];
                        }
                    }
                }
            }

            this.max_d = 0;
            this.max_c = 0;
            
            for (let i = 0; i < this.mdToC.length; ++i) {
              if (this.mdToC[i] != undefined) {
                this.max_d = Math.max(this.max_d, this.mdToC[i].length - 1);
                for (let j = 0; j < this.mdToC[i].length; ++j) {
                    if (this.mdToC[i][j] != undefined) {
                        this.max_c = Math.max(this.max_c, this.mdToC[i][j]);
                    }
                }
              }
            }

            for (let r = 0; r < inputFile.R; ++r) {
                let t2 = this.operations[r].t2[this.operations[r].t2.length - 1];
                let d = parseInt((t2 + inputFile.SECONDS_A_DAY - 1)/inputFile.SECONDS_A_DAY);
                this.max_d = Math.max(this.max_d, d);
            }

            for (let i = 0; i < M; ++i) {
                if (this.mdToC[i] == undefined) this.mdToC[i] = [];
                for (let j = 0; j <= this.max_d; ++j) {
                    if (this.mdToC[i][j] == undefined) {
                        this.mdToC[i][j] = DEFAULT_CPAPCITY;
                    }
                }
            }


        }
        return OutputFile;
    }());
    var TesterFrame = /** @class */ (function () {
        function TesterFrame(input, output) {
            this.input = input;
            this.output = output;
            this.grossP = 0;
            for (let r = 0; r < input.R; ++r) {
                let d = (input.orders[r].d - 1)*input.SECONDS_A_DAY;
                let t2 = output.operations[r].t2[output.operations[r].t2.length - 1];
                if (t2 <= d) this.grossP += input.orders[r].pr;
            }

            this.cost = 0.0;
            for (let m = 0; m < input.M; ++m) {
                for (let d = 1; d <= output.max_d; ++d) {
                    if (output.mdToC[m][d] != input.DEFAULT_CPAPCITY) {
                        this.cost += input.C[m] * Math.pow(output.mdToC[m][d] - input.DEFAULT_CPAPCITY, 1.1);
                    }
                }
            }
            this.cost = Math.ceil(this.cost);

            this.profit = this.grossP - this.cost;
        }
        return TesterFrame;
    }());
    var Tester = /** @class */ (function () {
        function Tester(inputContent, outputContent) {
            var input = new InputFile(inputContent);
            var output = new OutputFile(outputContent, input);
            this.frame = new TesterFrame(input, output);
        }
        return Tester;
    }());
    var Visualizer = /** @class */ (function () {
        function Visualizer() {
            this.grossProfitInput = document.getElementById('grossP');
            this.costSumInput = document.getElementById('cost');
            this.totalProfitInput = document.getElementById('score');
            this.tooltipDiv = document.getElementById("tooltip");
            this.drawingElement = document.getElementById('drawing');
            this.zoominButton = document.getElementById('zoomin');
            this.zoomoutButton = document.getElementById('zoomout');
            this.resizeButton = document.getElementById('resize');
            this.padding = 14;
            this.width = this.drawingElement.clientWidth - (2*this.padding);
            this.height = this.drawingElement.clientHeight - (2*this.padding);
            this.svg = SVG('drawing').size(this.width, this.height);
            this.defaultViewbox = this.svg.viewbox();
        }
        Visualizer.prototype.drawChart = function (frame) {
            var _this = this;
            this.svg.remove();
            this.width = this.drawingElement.clientWidth - (2*this.padding);
            this.height = this.drawingElement.clientHeight - (2*this.padding);
            this.svg = SVG('drawing').size(this.width, this.height);
            var input = frame.input;
            var output = frame.output;

            /* レイアウトに必要な数値計算 */
            var rowHeight = Math.min(150, this.height/input.M);
            var chartHeight = rowHeight * 0.9;
            var machineDetailHeight = rowHeight * 0.075;
            var verticalLabelWidth = this.width * 0.04;
            var chartpadding = chartHeight*0.1;
            var verticalTextSize = verticalLabelWidth*0.2;
            var chartWidth = this.width - verticalLabelWidth - verticalTextSize*2;

            var verticalLabelmax = output.max_c;
            if (verticalLabelmax < 1000) {
                verticalLabelmax = parseInt(verticalLabelmax/10 + 1) * 10;
            } else {
                verticalLabelmax = parseInt(verticalLabelmax/100 + 1) * 100;
            }


            /* 各設備の大枠を描写 */
            for (let m = 0; m < input.M; ++m) {
                let mathineDetailText = "設備m: " + (m+1) + ", 能力増加コストCm: " + input.C[m] + ", 製造時関係数Dm: " + input.D[m];
                /* 設備のデータテキストを配置 */
                this.svg.text(mathineDetailText).font({
                    size: machineDetailHeight*0.9,
                    family: 'Menlo, sans-serif',
                    fill: '#000'}).move(verticalLabelWidth+(machineDetailHeight*0.9)*2, m*rowHeight);
                /* 縦軸のテキストを配置 */ 
                this.svg.text("" + verticalLabelmax).font({
                    size: verticalTextSize,
                    family: 'Menlo, sans-serif',
                    anchor: 'end',
                    fill: '#000'}).move(verticalLabelWidth, m*rowHeight + machineDetailHeight - verticalTextSize*0.5 + chartpadding);
                this.svg.text("" + parseInt(verticalLabelmax/2)).font({
                    size: verticalTextSize,
                    family: 'Menlo, sans-serif',
                    anchor: 'end',
                    fill: '#000'}).move(verticalLabelWidth, m*rowHeight + machineDetailHeight - verticalTextSize*0.5 + chartHeight/2);
                this.svg.text("0").font({
                    size: verticalTextSize,
                    family: 'Menlo, sans-serif',
                    anchor: 'end',
                    fill: '#000'}).move(verticalLabelWidth, (m+1)*rowHeight - verticalTextSize*0.5 - chartpadding);

                /* 日付区切り等の線を配置 */
                let bx1 = verticalLabelWidth+verticalTextSize;
                let bx2 = this.width;
                let by = (m+1)*rowHeight -chartpadding;
                this.svg.line(bx1, by, bx2, by).stroke({color: '#000', width: 0.5 });
                for (let d = 1; d <= output.max_d; ++d) {
                    let x = (chartWidth/output.max_d)*d + verticalLabelWidth + verticalTextSize;
                    let y1 = m*rowHeight+machineDetailHeight+chartpadding;
                    let y2 = (m+1)*rowHeight-chartpadding;
                    this.svg.line(x, y1, x, y2).stroke({color: '#000', width: 0.5});
                    if (output.max_d <= 30) {
                        this.svg.text("day" + d).font({
                        size: verticalTextSize,
                        family: 'Menlo, sans-serif',
                        anchor: 'end',
                        fill: '#000'}).move(x, y1-verticalTextSize);
                    } else if (output.max_d <= 99){
                        this.svg.text("" + d).font({
                        size: verticalTextSize*0.8,
                        family: 'Menlo, sans-serif',
                        anchor: 'end',
                        fill: '#000'}).move(x, y1-verticalTextSize*0.8);
                    } else {
                        this.svg.text("" + d).font({
                        size: verticalTextSize*0.4,
                        family: 'Menlo, sans-serif',
                        anchor: 'end',
                        fill: '#000'}).move(x, y1-verticalTextSize*0.4);
                    }
                }

                /* 能力値を描写 */
                for (let d = 1; d <= output.max_d; ++d) {
                    let line;
                    let x1 = (chartWidth/output.max_d)*(d-1) + verticalLabelWidth + verticalTextSize
                    let x2 = (chartWidth/output.max_d)*d + verticalLabelWidth + verticalTextSize
                    let y = (m+1)*rowHeight - chartpadding - ((chartHeight-2*chartpadding)/verticalLabelmax * output.mdToC[m][d]);
                    line = this.svg.line(x1, y-2, x2, y-2).stroke({color: '#fff', opacity: 0, width: 5});
                    this.svg.line(x1, y, x2, y).stroke({color: '#000', width: 0.5});
                    let str = "日付: " + d + "<br>" + "能力値: " + output.mdToC[m][d] + "<br>";
                    line.mouseover(function (evt) { _this.linemouseOn(line, str, evt); })
                        .mouseout(function (evt) { _this.linemouseOff(line, evt); });
                }

            }

            /* オーダごとに作業を描写 */
            var rects = [];
            for (let r = 0; r < input.R; ++r) {
                let orderColor = this.color(r);
                rects[r] = [];
                let i = input.orders[r].i;
                for (let p = 0; p < input.boms[i].p; ++p) {
                    rects[r][p] = [];   
                    let m = output.operations[r].pTom[p];
                    let t1 = output.operations[r].t1[p];
                    let t2 = output.operations[r].t2[p];
                    while (t2 > t1) {
                        let nDay = parseInt((t1 + input.SECONDS_A_DAY)/input.SECONDS_A_DAY);
                        nDay = Math.max(1, nDay);
                        let capa = output.mdToC[m][nDay];
                        let height = (chartHeight - 2*chartpadding)/verticalLabelmax * capa;
                        let width = Math.min(t2-t1, nDay*input.SECONDS_A_DAY - t1)/(input.SECONDS_A_DAY+0.0) * (chartWidth/output.max_d);
                        let x = verticalLabelWidth + verticalTextSize + t1/(input.SECONDS_A_DAY+0.0) * (chartWidth/output.max_d);

                        let y = (m+1)*rowHeight - chartpadding - height;
                        rects[r][p].push(this.svg.rect(width, height).fill({color: orderColor, opacity: 0.95}).attr({stroke: '#fff', 'stroke-width': 5, 'stroke-opacity': 0}).move(x, y));
                        t1 = Math.min(t2, nDay*input.SECONDS_A_DAY);
                    }
                }
            }

            /* 納期遅れオーダを探す */
            for (let r = 0; r < input.R; ++r) {
                if ((input.orders[r].d-1)*input.SECONDS_A_DAY < output.operations[r].t2[output.operations[r].t2.length - 1]) {
                    let i = input.orders[r].i;
                    for (let p = 0; p < input.boms[i].p; ++p) {
                        let m = output.operations[r].pTom[p];
                        let t1 = output.operations[r].t1[p];
                        let t2 = output.operations[r].t2[p];
                        let d = parseInt(((t1+t2)/2 + input.SECONDS_A_DAY)/input.SECONDS_A_DAY);
                        let x = verticalLabelWidth + verticalTextSize + ((t1+t2)/2/input.SECONDS_A_DAY)*(chartWidth/output.max_d);
                        let y = (m+1)*rowHeight - chartpadding - (chartHeight-2*chartpadding)/verticalLabelmax*output.mdToC[m][d];
                        this.svg.text("!").font({
                            size: 2*verticalTextSize,
                            family: 'Menlo, sans-serif',
                            fill: '#f00'}).move(x-verticalTextSize/2.1, y-verticalTextSize*2.1);
                    }
                }
            }


            /* マウスホバーで線とオーダ情報を表示 */
            var lines = [];
            var strs = [];
            var timeFormatter = function (time) {
              var day = parseInt((time+input.SECONDS_A_DAY)/input.SECONDS_A_DAY);
              var hour = parseInt((time-input.SECONDS_A_DAY*(day-1))/3600);
              var minute = parseInt((time-input.SECONDS_A_DAY*(day-1)-3600*hour)/60);
              var second = parseInt((time-input.SECONDS_A_DAY*(day-1)-3600*hour-60*minute));
              return day + "日目" + hour + "時" + minute + "分" + second + "秒";
            }
            for (let r = 0; r < input.R; ++r) {
                lines[r] = [];
                strs[r] = [];
                let i = input.orders[r].i;
                for (let p = 0; p < input.boms[i].p; ++p) {
                    /* オーダの情報をまとめた文字列を作る */
                    let str = "オーダ番号: " + (r+1) + "<br>" + 
                    "品目番号: " + (input.orders[r].i+1) + "<br>" +
                    "工程番号: " + (p+1) + "<br>" +
                    "製造数量: " + input.orders[r].q + "<br>" +
                    "粗利金額: " + input.orders[r].pr + "<br>" +
                    "最早開始日: " + input.orders[r].e + "日目<br>" +
                    "納期日: " + input.orders[r].d + "日目<br>" +
                    "現在工程の製造開始時刻: " + timeFormatter(output.operations[r].t1[p]) + "(" + output.operations[r].t1[p] + ")" + "<br>" +
                    "現在工程の製造終了時刻: " + timeFormatter(output.operations[r].t2[p]) + "(" + output.operations[r].t2[p] + ")" + "<br>";

                    strs[r][p] = str;
                    let S = rects[r][p].length;
                    for (let s = 0; s < S; ++s) {
                        /* オーダを紐付ける線の配列を作る */
                        let width = rects[r][p][s].width();
                        let height = rects[r][p][s].height();
                        let x = rects[r][p][s].x();
                        let y = rects[r][p][s].y();
                        if (s == 0) {
                            lines[r].push(this.svg.line(x, y, x, y+height).stroke({color: '#000', width: 0}));
                            lines[r].push(this.svg.line(x, y, x+width, y).stroke({color: '#000', width: 0}));
                            lines[r].push(this.svg.line(x, y+height, x+width, y+height).stroke({color: '#000', width: 0}));
                            if (s+1 == S) {
                                lines[r].push(this.svg.line(x+width, y, x+width, y+height).stroke({color: '#000', width: 0}));
                            } else {
                                let nxtX = rects[r][p][s+1].x();
                                let nxtY = rects[r][p][s+1].y();
                                lines[r].push(this.svg.line(x+width, y, nxtX, nxtY).stroke({color: '#000', width: 0}));
                            }
                        } else if (s+1 == S) {
                            lines[r].push(this.svg.line(x, y, x+width, y).stroke({color: '#000', width: 0}));
                            lines[r].push(this.svg.line(x, y+height, x+width, y+height).stroke({color: '#000', width: 0}));
                            lines[r].push(this.svg.line(x+width, y, x+width, y+height).stroke({color: '#000', width: 0}));
                        } else {
                            lines[r].push(this.svg.line(x, y, x+width, y).stroke({color: '#000', width: 0}));
                            lines[r].push(this.svg.line(x, y+height, x+width, y+height).stroke({color: '#000', width: 0}));
                            let nxtX = rects[r][p][s+1].x();
                            let nxtY = rects[r][p][s+1].y();
                            lines[r].push(this.svg.line(x+width, y, nxtX, nxtY).stroke({color: '#000', width: 0}));
                        }
                    }

                    if (p != 0) {
                        let preM = output.operations[r].pTom[p-1];
                        let nxtM = output.operations[r].pTom[p];
                        let preW = rects[r][p-1][rects[r][p-1].length-1].width();
                        let preX = rects[r][p-1][rects[r][p-1].length-1].x();
                        let preY = rects[r][p-1][rects[r][p-1].length-1].y();
                        let nxtX = rects[r][p][0].x();
                        let nxtY = rects[r][p][0].y();
                        if (preM < nxtM) {
                            let preH = rects[r][p-1][rects[r][p-1].length-1].height();
                            lines[r].push(this.svg.line(preX+preW, preY+preH, nxtX, nxtY).stroke({color: '#000', width: 0}));
                        } else if (preM == nxtM) {
                            lines[r].push(this.svg.line(preX+preW, preY, nxtX, nxtY).stroke({color: '#000', width: 0}));
                        } else {
                            let nxtH = rects[r][p][0].height();
                            lines[r].push(this.svg.line(preX+preW, preY, nxtX, nxtY+nxtH).stroke({color: '#000', width: 0}));
                        }
                    }

                    if (p == 0) {
                        let m = output.operations[r].pTom[p];
                        let x = verticalLabelWidth + verticalTextSize + (chartWidth/output.max_d)*(input.orders[r].e-1);
                        let y1 = m*rowHeight + machineDetailHeight + chartpadding;
                        let y2 = (m+1)*rowHeight - chartpadding;
                        lines[r].push(this.svg.line(x, y1, x, y2).stroke({color: '#f00', width: 0}));
                    }

                    if (p+1 == input.boms[i].p) {
                        let m = output.operations[r].pTom[p];
                        let x = verticalLabelWidth + verticalTextSize + (chartWidth/output.max_d)*(input.orders[r].d-1);
                        let y1 = m*rowHeight + machineDetailHeight + chartpadding;
                        let y2 = (m+1)*rowHeight - chartpadding;
                        lines[r].push(this.svg.line(x, y1, x, y2).stroke({color: '#f00', width: 0}));
                    }
                }
            }

            for (let r = 0; r < input.R; ++r) {
                let i = input.orders[r].i;
                for (let p = 0; p < input.boms[i].p; ++p) {
                    for (let s = 0; s < rects[r][p].length; ++s) {
                        let str = strs[r][p];
                        rects[r][p][s].mouseover(function (evt) {
                            _this.rectsmouseOn(lines[r], str, evt);
                        })
                        rects[r][p][s].mouseout(function (evt) {
                            _this.rectsmouseOff(lines[r], evt);
                        })
                    }
                }
            }
        }

        Visualizer.prototype.setScore = function (frame) {
            this.grossProfitInput.value = String(frame.grossP).replace( /(\d)(?=(\d\d\d)+(?!\d))/g, '$1,');
            this.costSumInput.value = String(frame.cost).replace( /(\d)(?=(\d\d\d)+(?!\d))/g, '$1,');
            this.totalProfitInput.value = String(frame.profit).replace( /(\d)(?=(\d\d\d)+(?!\d))/g, '$1,');
        }
        Visualizer.prototype.setZoomAction = function () {
            // this.reloadButton.addEventListener('click', this.reloadFilesClosure);
            var _this = this;
            this.zoominButton.addEventListener('click', function(){
                var viewbox = _this.svg.viewbox();
                _this.svg.viewbox(viewbox.x, viewbox.y, viewbox.width*0.95, viewbox.height*0.95);
            });
            this.zoomoutButton.addEventListener('click', function(){
                var viewbox = _this.svg.viewbox();
                _this.svg.viewbox(viewbox.x, viewbox.y, viewbox.width*1.05, viewbox.height*1.05);
            });
            this.resizeButton.addEventListener('click', function(){
                _this.svg.viewbox(_this.defaultViewbox);
            });
            this.drawingElement.addEventListener('mousedown', function (evt) {
                var x = evt.clientX;
                var y = evt.clientY;
                var viewbox = _this.svg.viewbox();
                var mmove = function (evt) {
                    var nx = evt.clientX;
                    var ny = evt.clientY;
                    _this.svg.viewbox(viewbox.x-(nx-x), viewbox.y-(ny-y), viewbox.width, viewbox.height);
                }
                var mup = function () {
                    _this.drawingElement.removeEventListener('mousemove', mmove);
                    _this.drawingElement.removeEventListener('mouseup', mup);
                }
                _this.drawingElement.addEventListener('mousemove', mmove);
                _this.drawingElement.addEventListener('mouseup', mup);
            });
            this.zoominButton.classList.remove('disabled');
            this.zoomoutButton.classList.remove('disabled');
            this.resizeButton.classList.remove('disabled');
        }
        Visualizer.prototype.draw = function (frame) {
            this.setScore(frame);
            this.drawChart(frame);
            this.setZoomAction();
        }
        Visualizer.prototype.rectsmouseOn = function (lines, str, evt) {
            for (let i = 0; i < lines.length; ++i) {
                lines[i].stroke({width: 2});
            }
            this.tooltipDiv.innerHTML = str;
            this.tooltipDiv.style.display = "block";
            this.tooltipDiv.style.left = (evt.clientX + 50) + 'px';
            this.tooltipDiv.style.top = (evt.clientY - 200) + 'px';


        }
        Visualizer.prototype.rectsmouseOff = function (lines, evt) {
            for (let i = 0; i < lines.length; ++i) {
                lines[i].stroke({width : 0});
            }
            this.tooltipDiv.style.display = "none";
        }
        Visualizer.prototype.linemouseOn = function (line, str, evt) {
            line.stroke({color: '#000', opacity: 1});
            this.tooltipDiv.innerHTML = str;
            this.tooltipDiv.style.display = "block";
            this.tooltipDiv.style.left = (evt.clientX + 10) + 'px';
            this.tooltipDiv.style.top = (evt.clientY - 10) + 'px';

        }
        Visualizer.prototype.linemouseOff = function (line, evt) {
            line.stroke({color: '#fff', opacity: 0});
            this.tooltipDiv.style.display = "none";
        }
        Visualizer.prototype.hideTooltip = function (evt) {
            this.tooltipDiv.style.display = "none";
        };
        Visualizer.prototype.color = function (r) {
            var color = [];
            for (let i = 0; i < 3; ++i) {
                let t = ((r%2)*200+r*10+(r+1)*(i+1)*100)%255;
                t = Math.max(t, 0);
                t = Math.min(t, 255);
                color.push(t);
            }
            return "#" + color.map( function ( value ) {
                return ( "0" + value.toString( 16 ) ).slice( -2 ) ;
            } ).join( "" ) 
        };
        return Visualizer;
    }());
    var App = /** @class */ (function () {
        function App() {
            var _this = this;
            this.visualizer = new Visualizer();
            this.loader = new framework.FileSelector();
            this.loader.callback = function (inputContent, outputContent) {
                _this.tester = new Tester(inputContent, outputContent);
                _this.visualizer.draw(_this.tester.frame);
            };
        }
        return App;
    }());
    visualizer.App = App;
})(visualizer || (visualizer = {}));
window.onload = function () {
    new visualizer.App();
};
