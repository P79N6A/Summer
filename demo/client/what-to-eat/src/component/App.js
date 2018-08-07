import React from 'react';

import Welcome from './Welcome.js';
import Select from './Select.js';
import Option from './Option.js';
import Result from './Result.js';


class App extends React.Component {
    constructor (props) {
        super(props);
        this.state = {
            showWelcome:false,
            showSelect: false,
            showOption: false,
            showResult: false
        };
    };

    componentWillMount () {
        this.showWelcome();
    };

    showWelcome () {
        this.setState({
            showWelcome: true,
            showSelect: false,
            showOption: false,
            showResult: false
        });
    };

    showSelect () {
        this.setState({
            showWelcome: false,
            showSelect: true,
            showOption: false,
            showResult: false
        });
    };

    showOption () {
        this.setState({
            showWelcome: false,
            showSelect: false,
            showOption: true,
            showResult: false
        });
    };

    showResult(){
        this.setState({
            showWelcome: false,
            showSelect: false,
            showOption: false,
            showResult: true
        });
    };

    render () {
        let view;
        if (this.state.showWelcome) {
            view = <Welcome displaySelected = {()=>{this.showSelect();}}/>;
        } else if (this.state.showSelect) {
            view = <Select getResult = {()=>{this.showResult();}} addOption = {()=>{this.showOption();}} />;
        } else if (this.state.showOption) {
            view = <Option submitAdd = {()=>{this.showSelect();}} />;
        } else {
            view= <Result rollAgain = {()=>{this.showSelect();}} />;
        }
        return view;
    };
}

export default App;
