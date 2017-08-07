import React,{Component} from 'react';
import { Spin } from 'antd';
import 'antd/dist/antd.css';

class Welcome extends Component{
    constructor (props) {
        super(props);
        this.welcomeDelay = 1000;
    };
    componentDidMount() {
        setTimeout(()=>{
            this.props.displaySelected();
        }, this.welcomeDelay);
    };
    
    render () {
        return (
            <div>
                <Spin size="large" />
                <div>来一次紧张赤鸡的Roll？</div>
            </div>
        );
    }
};

export default Welcome;